//
//
//  Copyright (C) 2019 Greg Landrum
//
//   @@ All Rights Reserved @@
//  This file is part of the RDKit.
//  The contents are covered by the terms of the BSD license
//  which is included in the file license.txt, found at the root
//  of the RDKit source tree.
//
#include <string>
#include <iostream>
#include "minilib.h"

#include <RDGeneral/versions.h>
#include <GraphMol/RDKitBase.h>
#include <GraphMol/SmilesParse/SmilesParse.h>
#include <GraphMol/Fingerprints/MorganFingerprints.h>
#include <DataStructs/BitOps.h>

using namespace RDKit;

std::string get_morgan_fingerprint(std::string smiles, unsigned int radius,
                                 unsigned int length) {
  auto mol = SmilesToMol(smiles);
  auto fp = MorganFingerprints::getFingerprintAsBitVect(mol, radius, length);
  std::string res = BitVectToText(*fp);
  delete fp;
  return res;
}

std::string version() { return std::string(rdkitVersion); }

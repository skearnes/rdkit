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
#include <GraphMol/Substruct/SubstructMatch.h>

using namespace RDKit;

namespace {
ROMol *mol_from_input(const std::string &input) {
  RWMol *res = nullptr;
  SmilesParserParams ps;
  ps.sanitize = false;
  res = SmilesToMol(input, ps);
  if (res) {
    try {
      MolOps::sanitizeMol(*res);
      MolOps::assignStereochemistry(*res, true, true, true);
    } catch (...) {
      delete res;
      res = nullptr;
    }
  }
  return res;
}

ROMol *qmol_from_input(const std::string &input) {
  RWMol *res = nullptr;
  res = SmartsToMol(input);
  return res;
}
}  // namespace

JSMol *get_mol(const std::string &input) {
  ROMol *mol = mol_from_input(input);
  return new JSMol(mol);
}

JSMol *get_qmol(const std::string &input) {
  ROMol *mol = qmol_from_input(input);
  return new JSMol(mol);
}

std::string version() { return std::string(rdkitVersion); }

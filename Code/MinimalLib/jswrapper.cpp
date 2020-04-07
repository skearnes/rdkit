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
#include <emscripten/bind.h>
#include "minilib.h"

using namespace emscripten;
EMSCRIPTEN_BINDINGS(RDKit_minimal) {
  class_<JSMol>("Mol")
      .function("is_valid", &JSMol::is_valid)
      .function("get_smiles", &JSMol::get_smiles)
      .function("get_molblock", &JSMol::get_molblock)
      .function("get_inchi", &JSMol::get_inchi)
      .function("get_substruct_match", &JSMol::get_substruct_match)
      .function("get_substruct_matches", &JSMol::get_substruct_matches)

      // functionality primarily useful in ketcher
      .function("get_stereo_tags", &JSMol::get_stereo_tags)
      .function("get_aromatic_form", &JSMol::get_aromatic_form)
      .function("get_kekule_form", &JSMol::get_kekule_form)
      .function("add_hs", &JSMol::add_hs)
      .function("remove_hs", &JSMol::remove_hs);

  function("version", &version);
  function("get_inchikey_for_inchi", &get_inchikey_for_inchi);
  function("get_mol", &get_mol, allow_raw_pointers());
  function("get_qmol", &get_qmol, allow_raw_pointers());
}

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

  function("version", &version);
  function("get_mol", &get_mol, allow_raw_pointers());
  function("get_qmol", &get_qmol, allow_raw_pointers());
}

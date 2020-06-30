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

const assert = require('assert');
const Module = require("../demo/RDKit_minimal.js");

// the goal here isn't to be comprehensive (the RDKit has tests for that),
// just to make sure that the wrappers are working as expected
function test_basics(){
    var fp1 = mol.get_morgan_fp("c1ccccc1O");
    assert.equal(fp1.length,2048);
    assert.equal((fp1.match(/1/g)||[]).length,11);
    var fp2 = mol.get_morgan_fp("c1ccccc1O",0,512);
    assert.equal(fp2.length,512);
    assert.equal((fp2.match(/1/g)||[]).length,3);
}

Module.onRuntimeInitialized = () => {
    console.log(Module.version());
    test_basics();
};





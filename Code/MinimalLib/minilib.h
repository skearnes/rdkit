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
#include <GraphMol/RDKitBase.h>

class JSMol {
 public:
  JSMol() : d_mol(nullptr){};
  JSMol(RDKit::ROMol *mol) : d_mol(mol){};
  std::string get_smiles() const;
  std::string get_molblock() const;
  std::string get_inchi() const;
  std::string get_substruct_match(const JSMol &q) const;
  std::string get_substruct_matches(const JSMol &q) const;

  bool is_valid() const { return d_mol.get() != nullptr; };

  // functionality primarily useful in ketcher
  std::string get_stereo_tags() const;
  std::string get_aromatic_form() const;
  std::string get_kekule_form() const;
  std::string remove_hs() const;
  std::string add_hs() const;

 private:
  std::unique_ptr<RDKit::ROMol> d_mol;
};

std::string get_inchikey_for_inchi(const std::string &input);
JSMol *get_mol(const std::string &input);
JSMol *get_qmol(const std::string &input);
std::string version();

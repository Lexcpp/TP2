#pragma once
#include "Medecin.h"
#include <vector>
#include <memory>
using namespace std;

class Pediatre: public Medecin
{
public:
    Pediatre(const string& nom, unsigned nbNbEnfantsSoignes, unsigned int niveau = 0);
    void setNbEnfantsSoignes(int nbNbEnfantsSoignes);
    unsigned getNbNbEnfantsSoignes() const;
    vector<string> getCertifications() const;
    void operator+=(const string& certification);
    float calculerSalaire() const override;
    ostream& afficher(ostream& out) const override;
    void examinerPatient(shared_ptr<Patient>& p);

private:
    const float salaireBase = 3000.0f;
    shared_ptr<Patient> patient_;
    unsigned nbEnfantsSoignes_;
    vector<string> certifications_;
};
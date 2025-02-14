#include "Infirmier.h"
#include <iostream>

int Infirmier::nTypeSoin_ = 0;

// TODO: Implémenter le constructeur de Infirmier.
// - Initialiser le nom, le prénom et le taux horaire de l'infirmier.
// - Initialiser heuresTravaillees_ à 0.
Infirmier::Infirmier(const string & nom, const std::string & prenom, const float & tauxHoraire) : 
    Employe(nom), prenom_(prenom), tauxHoraire_(tauxHoraire) 
{
    heuresTravaillees_ = 0U;
}

// TODO: Implémenter le constructeur de copie de Infirmier.
// - Copier tous les attributs de l'infirmier passé en paramètre.
Infirmier::Infirmier(const Infirmier &a): 
    prenom_(a.getPrenom()), tauxHoraire_(a.getTauxHoraire()), Employe(a.getNom()), 
    heuresTravaillees_(a.getHeuresTravaillees()), patient_(a.getPatient())          // et pour nTypeSoin ??
{
    for (auto &l : a.getListeChambre()) this->listeChambre_.push_back(l);
}


string Infirmier::getPrenom() const
{
    return prenom_;
}


vector<string> Infirmier::getListeChambre() const{
    return listeChambre_;
}

float Infirmier::getTauxHoraire() const{
	 return tauxHoraire_;
}

const shared_ptr<Patient> Infirmier::getPatient() const{
    return patient_;
}

void Infirmier::setPrenom (const string& prenom)
{
	prenom_ = prenom;
}

void Infirmier::setTauxHoraire (const float& taux)
{
	tauxHoraire_ = taux;
}

void Infirmier::setPatient(const shared_ptr<Patient>& p){
    patient_ = p;
}

unsigned Infirmier::getHeuresTravaillees() const{
    return heuresTravaillees_;
}

// TODO: Surcharger l'opérateur += pour ajouter une chambre à la liste des chambres.
// - Ajouter le numéro de la chambre à la liste des chambres.
// -utiliser la fonction to_string pour la conversion
void Infirmier::operator+=(int numeroSalle){
    this->listeChambre_.push_back(to_string(numeroSalle));
}

void Infirmier::ajouterHeuresTravaillees(unsigned heures){
    heuresTravaillees_+= heures;
}   
  
float  Infirmier::calculerSalaire() const {
	float salaire = heuresTravaillees_ * tauxHoraire_ + listeChambre_.size() * tauxHoraire_ / 20.0;
	return  salaire;
}

// TODO: Implémenter la méthode examinerPatient.
// - Ajouter 5 heures travaillées à l'infirmier.
// - Ajouter la chambre du patient aux chambres de l'infirmiere
// - Assigner le patient à l'infirmier. indice: utilise static_cast et nTypeSoin
// - Mettre à jour le type de soins du patient. 
// - mettre à jour nTypeSoin NB: il ne devra jamais depasser 3. Il prend uniquemnt les valeurs 0 1 et 2.
void Infirmier::examinerPatient(shared_ptr<Patient>& p) {
    this->ajouterHeuresTravaillees(5U);
    *this += p->getSalle();
    this->patient_ = p;
    
    
}

ostream &Infirmier::afficher(ostream &out) const
{
	Employe::afficher(out);
    out << "Prenom: " << prenom_ << endl;
    out << "Taux horaire: " << tauxHoraire_ << " $/h" << endl;
    out << "Heures travaillees: " << heuresTravaillees_ << " heures" << endl;
    out << "Liste des chambres: ";
    if (listeChambre_.empty()) {
        out << "Aucune chambre assignee.";
    } else {
        for (const auto& chambre : listeChambre_) {
            out << chambre << " ";
        }
    }
    out << endl;
    return out;
}

bool Infirmier::operator==(const Infirmier &rhs) const{
    return nom_ == rhs.nom_ && prenom_ == rhs.prenom_;
}
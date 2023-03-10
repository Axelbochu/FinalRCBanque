#include "Customer_for_JSON.hpp"

ptree get_a_ptree_from_a_customer(client &customer) {
    ptree pt;
    ptree account_numbers;

    pt.put("numero_client", customer.numeroClientGet());
    pt.put("Nom", customer.nomGet());
    pt.put("Prenom", customer.prenomGet());
    pt.put("dateNaissance", customer.dateNaissanceGet());
   // pt.put("numeroAdresse", customer.numeroAdresseGet());
   // pt.put("adresse", customer.adresseGet());
    pt.put("tel", customer.telGet());
    pt.put("compte_courant", customer.comptecourantGet());
    pt.put("compte_epargne", customer.compteepargneGet());
    pt.put("interet", customer.interetGet());

    return pt;
}

client get_a_customer_from_a_ptree(ptree& pt) {

    int numero_client = pt.get<int>("numero_client");

    string Nom = pt.get<string>("Nom");
    string Prenom = pt.get<string>("Prenom");
    int dateNaissance = pt.get<int>("dateNaissance");

    //int numeroAdresse = pt.get<int>("numeroAdresse");
    //string adresse = pt.get<string>("adresse"); 
    int tel = pt.get<int>("tel", 0);

    int compte_courant = pt.get<int>("compte_courant", 0);
    int compte_epargne = pt.get<int>("compte_epargne", 0);
    int interet = pt.get<int>("interet", 0);



    client customer(numero_client,Nom,Prenom,dateNaissance,tel,compte_courant,compte_epargne,interet);

    return customer;
}

void add_customer1(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd1.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });
        
    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });
   

    pt_write.add_child("Customers", pt_accounts);

   
    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd1.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void add_customer2(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd2.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });

    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });


    pt_write.add_child("Customers", pt_accounts);


    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd2.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void add_customer3(client& customer) {
    ptree pt_in;
    ptree pt_accounts;
    ptree pt_write;
    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd3.json");
    read_json(file_in, pt_in);
    file_in.close();
    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto custom = get_a_customer_from_a_ptree(customer.second);
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(custom) });

    }
    // on ajoute le nouveau client au ptree
    pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer) });


    pt_write.add_child("Customers", pt_accounts);


    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd3.json");
    write_json(file_out, pt_write);
    file_out.close();
}

vector<client> json_to_vector1() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd1.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}
vector<client> json_to_vector2() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd2.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}
vector<client> json_to_vector3() {
    std::vector<client> cust;
    ptree pt_in;

    //on recuper les client deja present dans le json 
    ifstream file_in("../../../../Boost_JSON/bdd3.json");
    read_json(file_in, pt_in);
    file_in.close();

    // on les ajoute tous a un ptree
    for (ptree::value_type& customer : pt_in.get_child("Customers")) {
        auto customer_f_ptree = get_a_customer_from_a_ptree(customer.second);
        cust.push_back(customer_f_ptree);

    }
    return cust;
}
void vector1_to_json(vector<client> customer_vec) {
    ptree pt_accounts;
    ptree pt_write;
    for (int i = 0; i < (customer_vec.size());i++) {
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer_vec[i])});
    }
    pt_write.add_child("Customers", pt_accounts);

    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd1.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void vector2_to_json(vector<client> customer_vec){
    ptree pt_accounts;
    ptree pt_write;
    for (int i = 0; i < (customer_vec.size()); i++) {
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer_vec[i]) });
    }
    pt_write.add_child("Customers", pt_accounts);

    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd2.json");
    write_json(file_out, pt_write);
    file_out.close();
}
void vector3_to_json(vector<client> customer_vec) {
    ptree pt_accounts;
    ptree pt_write;
    for (int i = 0; i < (customer_vec.size()); i++) {
        pt_accounts.push_back({ "", get_a_ptree_from_a_customer(customer_vec[i]) });
    }
    pt_write.add_child("Customers", pt_accounts);

    // on ecrit dans le json
    ofstream file_out("../../../../Boost_JSON/bdd3.json");
    write_json(file_out, pt_write);
    file_out.close();
}


vector<string> separationvirement(string enter) {

    
    string delimiter = "/";
    string token1 = enter.substr(0, enter.find(delimiter));
    int nbvir = atoi(token1.c_str());
    enter.erase(0, token1.length()+1);
    
    vector<string> sortie;

    size_t pos = 0;
    string token;
    int x = 0;
    while (x != nbvir) {
        pos = enter.find(delimiter);
        token = enter.substr(0, pos);
        cout << token << endl;
        sortie.push_back(token);
        enter.erase(0, pos + 1);
        x++;
    }
    return sortie;
}
int numagence(string enter) {
    string delimiter = ",";

    string token = enter.substr(0, enter.find(delimiter)); 
    int sortie = atoi(token.c_str());
    sortie = sortie % 1000;
    return sortie;
}

int numclient(string enter) {
    string delimiter = ",";
    string token = enter.substr(0, enter.find(delimiter));
    int sortie = atoi(token.c_str());
    return sortie;
}

int sommevirement(string enter) {
    string delimiter = ",";
    string token = enter.substr(enter.find(delimiter)+1,enter.length());
    int sortie = atoi(token.c_str());
    return sortie;
}


client virement(client customer, string enter) {
    int vir = sommevirement(enter);
    int solde = customer.comptecourantGet();
    int total = solde + vir;
    customer.comptecourantSet(total);
    return customer;
}

client virement_negatif(client customer, string enter) {
    int vir = sommevirement(enter); 
    int solde = customer.comptecourantGet();
    int total = solde - vir;
    customer.comptecourantSet(total);
    return customer;
}
client virementLocal(client customer_send, client customer, int value) {
    
    int solde_customer = customer.comptecourantGet();
    int solde_customer_send = customer_send.comptecourantGet();
    int total_customer_send = solde_customer_send - value;
    int total = solde_customer + value;
    customer.comptecourantSet(total);
    return customer;
}
void epargne_to_courant(client* customer, int value) {
    int valeur_courant = customer->comptecourantGet();
    int valeur_epargne = customer->compteepargneGet();
    
    int total_courant = valeur_courant + value;
    int total_epargne = valeur_epargne - value;

    customer->comptecourantSet(total_courant);
    customer->compteepargneSet(total_epargne);
    int numagence = (customer->numeroClientGet()) / 1000;
    int numclient = (customer->numeroClientGet()) % 1000;

    if (numagence == 1) {

        vector<client> tmp = json_to_vector1();
        tmp[numclient] = *customer;
        vector1_to_json(tmp);

    }
    else if (numagence == 2) {
        vector<client> tmp = json_to_vector2();
        tmp[numclient] = *customer;
        vector2_to_json(tmp);
    }   
    else if (numagence == 3)
    {
        vector<client> tmp = json_to_vector3();
        tmp[numclient] = *customer ;
        vector3_to_json(tmp);
    }
    

}
void courant_to_epargne(client* customer, int value) {
    
    int valeur_courant = customer->comptecourantGet();
    int valeur_epargne = customer->compteepargneGet();

    int total_courant = valeur_courant - value;
    int total_epargne = valeur_epargne + value;

    customer->comptecourantSet(total_courant);
    customer->compteepargneSet(total_epargne);
    int numagence = (customer->numeroClientGet())/1000;
    int numclient = (customer->numeroClientGet()) % 1000;

    if (numagence == 1) {

        vector<client> tmp = json_to_vector1();
        tmp[numclient] = *customer;
        vector1_to_json(tmp);

    }
    else if(numagence == 2) {
        vector<client> tmp = json_to_vector2();
        tmp[numclient] = *customer;
        vector2_to_json(tmp);
    }
    else if( numagence == 3)
    {
        vector<client> tmp = json_to_vector3();
        tmp[numclient] = *customer;
        vector3_to_json(tmp);
    }
    
}



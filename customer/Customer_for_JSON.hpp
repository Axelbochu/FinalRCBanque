#pragma once

#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>

#ifdef _WIN32
#include <SDKDDKVer.h>
#endif

#include "Customer.hpp"
using namespace std;

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

ptree get_a_ptree_from_a_customer(client& customer);
client get_a_customer_from_a_ptree(ptree& pt);
void add_customer1(client& customer);
void add_customer2(client& customer);
void add_customer3(client& customer);
vector<client> json_to_vector1();
vector<client> json_to_vector2();
vector<client> json_to_vector3();
vector<string> separationvirement(string enter);
int numagence(string enter);
int numclient(string enter);
int sommevirement(string enter);
client virement(client customer, string enter);
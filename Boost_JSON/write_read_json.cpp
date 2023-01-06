#include "Customer_for_JSON.hpp"

int main(int argc, char** argv) {
    ptree pt_write;
    ptree pt_accounts;
    ptree pt_test;

    try {
        vector<client> tmp = json_to_vector1();
        courant_to_epargne(&tmp[0], 50);
    }
    catch (std::exception& e) {
        // Other errors
    }
}
//1098 4076
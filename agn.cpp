#include <iostream>
#include <string>
#include <fstream>

struct agn {
    std::string name;
    char number[12];
    std::string email;
};

int main() {
    std::string choice;
    int x;
    int index = 0;
    std::ofstream arq;

    agn usuario;
    agn ListaUsuario[5];
    
    while (true){   
        std::cout << "Nome: ";
        std::cin >> usuario.name;
        std::cout << "numero: ";
        std::cin >> usuario.number;
        std::cout << "email: ";
        std::cin >> usuario.email;

        ListaUsuario[index] = usuario;
        index++;

        std::cout << "--------------------\n";
        std::cout << "Quer add um novo usuario?[y/n]: ";
        std::cin >> choice;
        
        if (choice == "y") {
            std::cout << "--------------------\n";
        }
        else{
            break;
        }
    }
    for (int i = 0;i < sizeof(ListaUsuario)/sizeof(ListaUsuario[0]); i++) {
        if (ListaUsuario[i].name.length() > 0) {
            if (arq.is_open()) {
                arq << "usuario: " << i << "\n";
                arq << "nome: " << ListaUsuario[i].name << "\n";
                arq << "numero: " << ListaUsuario[i].number << "\n";
                arq << "email: " << ListaUsuario[i].email << "\n";
                arq << "--------------------\n"; 
            }
            else {
                arq.open("Agenda.txt", std::ios::app);
                arq << "usuario: " << i << "\n";
                arq << "nome: " << ListaUsuario[i].name << "\n";
                arq << "numero: " << ListaUsuario[i].number << "\n";
                arq << "email: " << ListaUsuario[i].email << "\n";
                arq << "--------------------\n";
            }

        }
    }
    arq.close();   
    return 0;
}
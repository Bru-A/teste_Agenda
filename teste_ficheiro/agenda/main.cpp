#include <iostream>
#include <stdlib.h>
using namespace std;
/*
Fazer um programa para simular uma agenda de telefones.
Para cada pessoa devem-se ter os seguintes dados:
  Nome
  E-mail
  Morada (Rua, número, complemento, código postal, cidade, distrito, país).
  Telefone
  Data de aniversário (contendo campo para dia, mês, ano).
  Observações: Uma linha (string) para alguma observação especial.
(a) Definir a estrutura acima.
(b) Declarar a variável agenda (vetor) com capacidade de agendar até 100 nomes.
(c) Definir um bloco de instruções que permite a pesquisa pelo primeiro nome e
imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime
para todas).
(d) Definir um bloco de instruções para inserir uma pessoa.
(e) Definir um bloco de instruções que imprime a agenda com as opções (Menu):
• Inserir novo contacto.
• Procurar nome.
• Listar todas pessoas: Imprime nome, telefone e e-mail.
• Listar todas pessoas: Imprime todos os dados.
(f) O programa deve ter um menu principal oferecendo as opções acima.
*/
struct Pessoa {
    string nome;
    string email;
    string morada;
    string telefone;
    string dataAniversario;
    string observacoes;
};
// Acesso global no programa para está variável
Pessoa agenda[100];
int quantidadePessoas = 0;
// Declarar os métodos
// Procurar por nome
void procuraNome(string nome);
// Inserir uma nova pessoa na agenda
void inserePessoa();
// Lê o ficheiro de texto e guarda no vetor agenda
void carregarDoFicheiro();
void listarTudo();
void listar();
// menu
void menu();
int main() {
    carregarDoFicheiro();
    while (1) {
        menu();
    }
}
// Procurar num array
void procuraNome(string nome) {
    for (int i = 0; i < quantidadePessoas - 1; i++) {
        if (agenda[i].nome == nome) {
            cout << "Nome: " << agenda[i].nome << "\nEmail: " << agenda[i].email
                 << "\nMorada: " << agenda[i].morada
                 << "\nTelefone: " << agenda[i].telefone
                 << "\nData aniversario: " << agenda[i].dataAniversario
                 << "\nObservações: " << agenda[i].observacoes << "\n";
        }
    }
}
// Gravar no ficheiro
void inserePessoa() {
    Pessoa p;
    cout << "Nome: \n";
    getline(cin, p.nome);
    cout << " Email: \n";
    cin >> p.email;
    cout << " Morada: \n";
    cin.ignore();
    getline(cin, p.morada);
    cout << " Telefone: \n";
    cin >> p.telefone;
    cout << " Data aniversario: \n";
    cin >> p.dataAniversario;
    cout << " Observações: \n";
    cin.ignore();
    getline(cin, p.observacoes);
    FILE *file;
    file = fopen("agenda.csv", "at");
    string pessoa = p.nome + ";" + p.email + ";" + p.morada + ";" + p.telefone +
                    ";" + p.dataAniversario + ";" + p.observacoes + "\n";
    fputs(pessoa.c_str(), file);
    fclose(file);
}
// Ler o ficheiro e transformar numa estrutura cada linha. Guardar num vetor
void carregarDoFicheiro() {
    FILE *file;
    file = fopen("agenda.csv", "rt");
    //Se ainda existir o ficheiro criamos
    if(file == NULL){
        file = fopen("agenda.csv", "wt");
        fclose(file);
        return;
    }
    char line[250];
    quantidadePessoas = 0;
    while (!feof(file)) {
        Pessoa tmp;
        tmp.nome = "";
        tmp.email = "";
        tmp.morada = "";
        tmp.telefone = "";
        tmp.dataAniversario = "";
        tmp.observacoes = "";
        fgets(line, 250, file);
        // cout << line << "\n";
        int i = 0;
        if (line[i] == NULL) {
            break;
        }
        while (line[i] != ';') {
            tmp.nome += line[i];
            i++;
        }
        i++;
        while (line[i] != ';') {
            tmp.email += line[i];
            i++;
        }
        i++;
        while (line[i] != ';') {
            tmp.morada += line[i];
            i++;
        }
        i++;
        while (line[i] != ';') {
            tmp.telefone += line[i];
            i++;
        }
        i++;
        while (line[i] != ';') {
            tmp.dataAniversario += line[i];
            i++;
        }
        i++;
        while (line[i] != '\n') {
            tmp.observacoes += line[i];
            i++;
        }
        agenda[quantidadePessoas] = tmp;
        quantidadePessoas += 1;
    }
}
void menu() {
    cout << "##### MENU #####\n"
         << "1) Inserir novo contacto\n2) Procurar por nome\n3) Limpar ecra\n4) "
            "Listar todos contactos(nome,email,telefone)\n5) Listar todos contactos (Toda info)\n6) Sair\n";
    int opcao;
    cin >> opcao;
    cin.ignore();
    if (opcao == 1) {
        inserePessoa();
        // Para carregar para a memoria do programa a nova pessoa
        carregarDoFicheiro();
    } else if (opcao == 2) {
        string nome;
        cout << "Escreva o nome: \n";
        getline(cin, nome);
        procuraNome(nome);
    } else if (opcao == 3) {
        system("clear");
    }else if(opcao == 4){
        listarTudo();
    }else if(opcao == 5){
        listar();
    }
    else {
        exit(0);
    }
}
//Percorrer o vetor agenda e imprimir os dados todos
void listarTudo(){
}
//Percorrer o vetor agenda e listar apenas nome, email e telefone.
void listar(){
}
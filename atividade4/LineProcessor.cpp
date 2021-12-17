#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
    std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
    // Neste exemplo usaremos expressoes regulares para verificar se uma linha
    // eh valida ou nao.
    //
    // Esta expressao regular eh formada por cinco partes. Cada uma dessas
    // partes eh um dos tres tipos de padrao regular abaixo:
    //
    // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
    // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
    // \\d+ eh qualquer sequencia de um ou mais digitos
    std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

    // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
    // a expressao regular que acabamos de criar:
    return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
    //
    // Em geral eh mais facil ler dados de uma string se a string eh transformada
    // em um objeto do tipo stringstream:
    std::stringstream ss(str);
    //
    // Iremos ler os dados da string nestas tres variaveis abaixo:
    std::string nomePais;
    unsigned populacao, percUrbana;
    //
    // Como sabemos que a linha contem string int int, podemos fazer a leitura
    // facilmente usando o operador de streaming:
    ss >> nomePais >> populacao >> percUrbana;
    //
    // Note que precisamos arredondar o valor que serah impresso. O arredondamento
    // serah feito via a funcao floor. Ou seja, decimais serao sempre
    // arredondados para baixo:
    unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
    //
    // Uma vez encontrados os valores que precisam ser impressos, seguimos o
    // modelo do enunciado do exercicio:
    std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
              std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
    std::regex regularExpr("^[^+-]+[0-9]+$");
    return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
    // TODO: Implemente este metodo:
    std::stringstream ss(str);
    int sum = 0;
    int value;
    while (ss >> value) {
        sum += value;
    }
    std::cout << sum << std::endl;

}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    std::regex regularExpr("([a-zA-Z]+[a-zA-Z]+\\s[0-9]\\s[a-zA-Z]+\\s[0-9])");
    return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    std::stringstream ss(str);
    std::string str_placar;
    std::vector<std::string> placar{};
    while (ss >> str_placar) {
        placar.push_back(str_placar);
    }
    if (std::stoi(placar[1]) > std::stoi(placar[3])) {
        std::cout << "Vencedor: " << placar[0] << std::endl;
    } else if (std::stoi(placar[1]) < std::stoi(placar[3])) {
        std::cout << "Vencedor: " << placar[2] << std::endl;
    } else {
        std::cout << "Empate" << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
    std::stringstream ss(str);
    std::string str_palavras;
    std::vector<std::string> palavras{};
    while (ss >> str_palavras) {
        palavras.push_back(str_palavras);
    }
    std::cout << palavras.size() << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    std::regex regularExpr("^([a-zA-ZÀ-ú]+\\s*)+$");
    return std::regex_match(str, regularExpr);
}

void InversorDeFrases::processaLinha(const std::string &str) {
    std::stringstream ss(str);
    std::string str_palavras;
    std::vector<std::string> palavras{};
    while (ss >> str_palavras) {
        palavras.push_back(str_palavras);
    }
    std::reverse(palavras.begin(),palavras.end());
    for(int i = 0 ; i < palavras.size() ; i++){
        std::cout << palavras[i] << " ";
    }

}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
    std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
    std::regex regularExpr(dateFormat);
    return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
    std::stringstream ss(str);
    std::string dia, mes_s, ano;
    std::getline(ss, dia, '/');
    std::getline(ss, mes_s, '/');
    std::getline(ss, ano, '/');
    int mes_i;
    mes_i = stoi(mes_s);
    if (mes_i == 1) {
        std::cout << "Jan"<< std::endl;
    } else if (mes_i == 2) {
        std::cout << "Fev"<< std::endl;
    } else if (mes_i == 3) {
        std::cout << "Mar"<< std::endl;
    } else if (mes_i == 4) {
        std::cout << "Abr"<< std::endl;
    } else if (mes_i == 5) {
        std::cout << "Mai"<< std::endl;
    } else if (mes_i == 6) {
        std::cout << "Jun"<< std::endl;
    } else if (mes_i == 7) {
        std::cout << "Jul"<< std::endl;
    } else if (mes_i == 8) {
        std::cout << "Ago"<< std::endl;
    } else if (mes_i == 9) {
        std::cout << "Set"<< std::endl;
    } else if (mes_i == 10) {
        std::cout << "Out"<< std::endl;
    } else if (mes_i == 11) {
        std::cout << "Nov"<< std::endl;
    } else if (mes_i == 12) {
        std::cout << "Dez"<< std::endl;
    }
}
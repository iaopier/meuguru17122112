#include "google_password.hpp"

#include <iostream>
#include <vector>
#include <set>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
    if(checkPassword(password)){
        Usuario u = Usuario(login,password);
        m_passwords.insert(std::pair<std::string,Usuario>(url,u));
    }
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
  m_passwords.erase(url);

}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& password) {
    std::map<std::string,Usuario>::iterator it;
    std::string passwordTest = m_passwords.find(url)->second.getPassword();
    if(old_password.compare(passwordTest) == 0 ){
        if(checkPassword(password)){
            m_passwords.find(url)->second.setPassword(password);
        }
    }
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
}

struct comp {
    bool operator()(const std::pair<std::string, Usuario>& a,
                    const std::pair<std::string, Usuario>& b) const
    {
        return a.first < b.first;
    }
};


void GooglePassword::printPasswords() {

    std::set<std::pair<std::string, Usuario>, comp> ordered(m_passwords.begin(),m_passwords.end());
    std::cout << ordered.size() << std::endl;
    for(auto &tupla : ordered){
        std::cout << tupla.first << ": " << tupla.second.getLogin() << " and " << tupla.second.getPassword() << std::endl;
    }
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
}

bool GooglePassword::checkPassword(const std::string& password) const {
    if(6 > password.length() || password.length() > 50){
        return false;
    }else{
        std::size_t found = password.find("123456");
        if(found!=std::string::npos)
            return false;
        found = password.find(' ');
        if(found!=std::string::npos)
            return false;
    }
    return true;

}


#include <iostream>
#include <vector>
#include <algorithm>

u_int16_t new_lfsr(u_int16_t lfsr)
{
    u_int16_t bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
    return (lfsr >> 1) | (bit << 15);
}
int valori_min_alfabetice()
{
    int min_alfabetice;
    std::cout << "Introdu numarul minim de caractere alfabetice: " << '\n';
    std::cin >> min_alfabetice;

    return min_alfabetice;
}

int valori_max_alfabetice()
{
    int max_alfabetice;
    std::cout << "Introdu numarul maxim de caractere alfabetice: " << '\n';
    std::cin >> max_alfabetice;

    return max_alfabetice;
}

int valori_min_numerice()
{
    int min_numerice;
    std::cout << "Introdu numarul minim de caractere numerice: " << '\n';
    std::cin >> min_numerice;

    return min_numerice;
}

int valori_max_numerice()
{
    int max_numerice;
    std::cout << "Introdu numarul maxim de caractere numerice: " << '\n';
    std::cin >> max_numerice;

    return max_numerice;
}

int valori_min_speciale()
{
    int min_speciale;
    std::cout << "Introdu numarul minim de caractere speciale: " << '\n';
    std::cin >> min_speciale;

    return min_speciale;
}

int valori_max_speciale()
{
    int max_speciale;
    std::cout << "Introdu numarul maxim de caractere speciale: " << '\n';
    std::cin >> max_speciale;

    return max_speciale;
}

int valori_total_caractere()
{
    int total_caractere;
    std::cout << "Introdu numarul total al caracterelor: " << '\n';
    std::cin >> total_caractere;

    return total_caractere;
}


int main()
{
    std::vector<int> litere;
    std::vector<int> cifre;
    std::vector<int> speciale;

    for(int i = 65; i <= 90; i++) litere.push_back(i);

    for(int i = 97; i<= 122; i++) litere.push_back(i);

    for(int i = 48; i <= 57; i++) cifre.push_back(i);

    speciale.insert(speciale.end(), {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 94, 95, 96});

    int min_alfabetice = valori_min_alfabetice();
    int max_alfabetice = valori_max_alfabetice();
    int min_numerice = valori_min_numerice();
    int max_numerice = valori_max_numerice();
    int min_speciale = valori_min_speciale();
    int max_speciale = valori_max_speciale();
    int total_caractere = valori_total_caractere();
    

    u_int16_t lfsr = 0x10101;
    int password_length = total_caractere;
    std::string parola_alfabetice;
    std::string parola_numerice;
    std::string parola_speciale;

    for(int i = 0; i < max_alfabetice; i++)
    {
        lfsr = new_lfsr(lfsr);
        char ch = static_cast<char>(litere[lfsr % litere.size()]);
        parola_alfabetice += ch;
    }

    for(int i = 0; i < max_numerice; i++)
    {
        lfsr = new_lfsr(lfsr);
        char ch = static_cast<char>(cifre[lfsr % cifre.size()]);
        parola_numerice += ch;
    }

    for(int i = 0; i < max_speciale; i++)
    {
        lfsr = new_lfsr(lfsr);
        char ch = static_cast<char>(speciale[lfsr % speciale.size()]);
        parola_speciale += ch;
    }

    std::cout << "parola generata: " << parola_alfabetice << '\n';
    std::cout << "parola numerice: " << parola_numerice << '\n';
    std::cout << "parola speciale: " << parola_speciale << '\n';
    std::string parola = parola_alfabetice + parola_numerice + parola_speciale;
    std::random_shuffle(parola.begin(), parola.end());
    std::cout << parola;
    
}

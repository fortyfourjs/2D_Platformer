#include <iostream>
#include <vector>
#include <algorithm>

u_int16_t fct_lfsr(u_int16_t lfsr)
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

int interval_separator()
{
    int nr_separator;
    std::cout << "Seteaza un separator: " << '\n';
    std::cin >> nr_separator;

    return nr_separator;
}
int alegere_nr_alfabetice(int lfsr, int min_alfabetice, int max_alfabetice) 
{
    if(min_alfabetice == max_alfabetice) 
        return min_alfabetice;
    else
        return min_alfabetice + (lfsr % (max_alfabetice - min_alfabetice) + 1);
}
int alegere_nr_numerice(int lfsr, int min_numerice, int max_numerice)
{
    if(min_numerice == max_numerice)
        return min_numerice;
    else
        return min_numerice + (lfsr % (max_numerice - min_numerice) + 1);
}
int alegere_nr_speciale(int lfsr, int min_speciale, int max_speciale)
{
    if(min_speciale == max_speciale)
        return min_speciale;
    else
        return min_speciale + (lfsr % (max_speciale - min_speciale) + 1);
}

int nr_parole_generate()
{
    int nr_parole;
    std::cout << "Cate parole doresti sa generezi?" << '\n';
    std::cin >> nr_parole;
    
    return nr_parole;
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
    int nr_separator = interval_separator();
    char separator = '-';
    
    /* u_int16_t lfsr = 0xACE1u; */ // seed initial, aceleasi rezultate 
    u_int16_t lfsr = static_cast<u_int16_t>(time(nullptr)); //seedul devine ora actuala in secunde.rezultatele difera de fiecare data
    int nr_alfabetice = alegere_nr_alfabetice(lfsr, min_alfabetice, max_alfabetice);
    int nr_numerice = alegere_nr_numerice(lfsr, min_numerice, max_numerice);
    int nr_speciale = alegere_nr_speciale(lfsr, min_speciale, max_speciale);



    if(total_caractere < min_alfabetice + min_numerice + min_speciale)//erori introducere date
    {
        std::cout << "Valorile minime introduse depasesc lungimea parolei \n";

        return 1;
    }
    if(total_caractere > max_alfabetice + max_numerice + max_speciale)//erori introducere date
    {
        std::cout << "Lungimea parolei este mai mare decat valorile maxime introduse \n";

        return 1;
    }
    
    int nr_parole = nr_parole_generate();
    
  
    for(int i = 0; i < nr_parole; ++i)
    {
    std::string parola_alfabetice;
    std::string parola_numerice;
    std::string parola_speciale;

    for(int i = 0; i < nr_alfabetice; i++)
    {
        lfsr = fct_lfsr(lfsr);
        char ch = static_cast<char>(litere[lfsr % litere.size()]);
        parola_alfabetice += ch;
    }

    for(int i = 0; i < nr_numerice; i++)
    {
        lfsr = fct_lfsr(lfsr);
        char ch = static_cast<char>(cifre[lfsr % cifre.size()]);
        parola_numerice += ch;
    }

    for(int i = 0; i < nr_speciale; i++)
    {
        lfsr = fct_lfsr(lfsr);
        char ch = static_cast<char>(speciale[lfsr % speciale.size()]);
        parola_speciale += ch;
    }

    std::string parola = parola_alfabetice + parola_numerice + parola_speciale; 

    for (int i = parola.size() - 1; i > 0; i--) //lfsr pe parola finala
    {
        lfsr = fct_lfsr(lfsr);
        int j = lfsr % (i + 1);
        
        char temp = parola[i];
        parola[i] = parola[j];
        parola[j] = temp;
    }

    std::cout << "parola nr." << i + 1 << ": "<< parola << '\n';
    }  
}

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

char getRandomChar() {
    const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[rand() % charset.size()]; // Randomly select a character from the charset
}

string randstring (int num)
{   
    string rstring;
    for (int i = 0; i < num; i++) {
        rstring += getRandomChar(); // Generate a random character and append it to the string
    }
    return rstring;
}

void rasyti(const string& filename, const string& data, int n)
{
    ofstream ofs(filename, ios::app);
    ofs << data << endl;  
    ofs.close();
}

void skaityti(string& fi)
{
    int failas;
    cout << "Is kurio failp skaityti duomenis?" << endl;
    cout << "1 - file1.txt (vienas simbolis)" << endl;
    cout << "2 - file2.txt (vienas simbolis skirtingas nuo pirmojo)" << endl;
    cout << "3 - file3.txt (1001 atsitiktinai sugeneruotu simboliu)" << endl;
    cout << "4 - file4.txt (1001 atsitiktinai sugeneruotu kitu simboliu)" << endl;
    cout << "5 - file5.txt (1001 atsitiktinai sugeneruotu dar kitu simboliu)" << endl;
    cout << "6 - file6.txt (toks pat kaip 5 failas, bet skiriasi 1 simboliu)" << endl;
    cout << "7 - tuscias.txt (tuscias failas)" << endl;
    cin >> failas;
    ifstream inf;
    if(failas == 1)
    inf.open("file1.txt");
    else if(failas == 2)
    inf.open("file2.txt");
    else if(failas == 3)
    inf.open("file3.txt");
    else if(failas == 4)
    inf.open("file4.txt");
    else if(failas == 5)
    inf.open("file5.txt");
    else if(failas == 6)
    inf.open("file6.txt");
    else if(failas == 7)
    inf.open("tuscias.txt");
    getline(inf, fi);
    inf.close();
}

string intihex(int num, int width = 8)
{
    stringstream ss;
    ss << hex << setw(width) << setfill('0') << num;
    return ss.str();
}

unsigned int mix(unsigned int a, unsigned int b)
{
    b *= 0xcc9e2d51;
    b = (b ^ (b >> 15));
    b *= 0x1b873593;

    a ^= b;
    a = (a ^ (a >> 16));
    a = a * 5 + 0xe6546b64;
    return a;
}

string hashfunction(const string& input)
{
    const int rnum = 4; // Extra mixing rounds
    unsigned int seedas = 0xdeadbeef;
    unsigned int temp = 0;

    for(size_t i = 0; i < input.size(); i++)
    {
        temp = input[i] * (i + 1); // Use the character value, scaled by its position
        seedas = mix(seedas, temp);
    }

    // Additional mixing rounds
    for(int i = 0; i < rnum; i++)
    {
        seedas = mix(seedas, temp);
    }

    string hstring;
    for(int i = 0; i < 8; i++)
    {
        seedas = mix(seedas, temp);
        hstring += intihex(seedas);
    }

    return hstring.substr(0, 64);
}

void skaitytkitka(string filename, int numl)
{
    ifstream inf(filename);
    string line;
    string kazkas;
    kazkas.clear();

    for (int i = 0; i < numl && getline(inf, line); ++i) {
        kazkas += line;
    }

    auto start = chrono::high_resolution_clock::now();
    string hashas = hashfunction(kazkas);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> hasht = end - start;
    cout << "Uzkoduota reiksme " << hashas << endl;
    cout << "Uzhashint uztruko " << hasht.count() << " s" << endl;
}

int main(){
    string inputas;
    string outputas;
    outputas.resize(64);
    //Generuojam failus
    string pirmasr = randstring(1001);
    string antrasr;
    string treciasr;
    do {
        antrasr = randstring(1001);
    }while(pirmasr == antrasr);
    do
    {
        treciasr = randstring(1001);
    } while (antrasr == treciasr);
    
    rasyti("file3.txt", pirmasr, 1);
    rasyti("file4.txt", antrasr, 1);
    rasyti("file5.txt", treciasr, 1);
    rasyti("file6.txt", treciasr, 1);
    //Baigiam generuot

    //Kuriam daug.txt
    ofstream ofs("daug.txt", ios::trunc);
    ofs.close();
    for(int i = 0; i< 25000; i++){
    string string10 = randstring(10);
    rasyti("daug.txt", string10, 25000);
    }

    for(int i = 0; i< 25000; i++){
    string string100 = randstring(100);
    rasyti("daug.txt", string100, 25000);
    }

    for(int i = 0; i< 25000; i++){
    string string500 = randstring(500);
    rasyti("daug.txt", string500, 25000);
    }

    for(int i = 0; i< 25000; i++){
    string string1000 = randstring(1000);
    rasyti("daug.txt", string1000, 25000);
    }

    //Baigiam kurt
    int a;
    cout << "Kaip rasyti inputa?" << endl;
    cout << "1 - ranka" << endl;
    cout << "2 - skaityti is failo" << endl;
    cout << "3 - skaityti is konstitucijos" << endl;
    cin >> a;
    if(a == 1)
    {
    cout << "Irasykite norima uzkoduoti reiksme " << endl;
    cin >> inputas;
    outputas = hashfunction(inputas);
    cout << "Uzkoduota reiksme " << outputas << endl;
    }
    if(a == 2)
    {
    skaityti(inputas);
    outputas = hashfunction(inputas);
    cout << "Uzkoduota reiksme " << outputas << endl;
    }
    if(a == 3)
    {
        int numl;
        cout << "Kiek eiluciu uzkoduoti?" << endl;
        cin >> numl;
        skaitytkitka("konstitucija.txt", numl);
    }
    return 0;
}


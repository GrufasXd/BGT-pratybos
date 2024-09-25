#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

string intihex(int num, int width = 8)
{
    stringstream ss;
    ss << hex << setw(width) << setfill('0') << num;
    return ss.str();
}

unsigned int mix(unsigned int a, unsigned int b)
{
    b *= 0xcc9e2d51;
    b = (b<15) | (b>>17);
    b *= 0x1b873593;

    a ^= b;
    a = (a<<15) | (b>>17);
    a = a * 5 + 0xe6546b64;
    return a;
}

string hashfunction(const string& input)
{
    const int rnum = 4;
    unsigned int seedas = 0xdeadbeef;
    unsigned int temp = 0;

    for(size_t i = 0; i < input.size(); i++)
    {
        temp = input[i] * (i+1);
        seedas = mix(seedas, temp);
    }

    for(int i = 0; i<rnum; i++)
    {
        seedas = mix(seedas, temp);
    }

    string hstring;
    for(int i = 0; i < 8; i++)
    {
        hstring += intihex(seedas);
        seedas = mix(seedas, temp);
    }

    return hstring.substr(0,64);
}

int main(){
    string inputas;
    string outputas;
    outputas.resize(64);
    cout << "Irasykite norima uzkoduoti reiksme " << endl;
    cin >> inputas;
    outputas = hashfunction(inputas);
    cout << "Uzkoduota reiksme " << outputas << endl;
    
    return 0;
}


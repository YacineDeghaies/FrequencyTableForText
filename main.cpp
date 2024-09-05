#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;


int main(){
    //create ifstream object
    ifstream myFile;

    //opens the file for reading
    myFile.open("lorem.txt");

    //check if file is opened successfully
    if(!myFile.is_open()){
        cerr<< "Erro opening the file!"<<endl;
        return 1;
    }

    //map to hold pairs of character + its freq
    map<int, int> ar;

    // Initialize the map with all possible ASCII characters
    for(int i = 0; i<256; ++i)
        ar[i] = 0;

    //get the frequency of each character in the input
    char ch;
    while(true){

        ch = myFile.get(); //get will return a Byte each time
        if(ch == EOF)
            break;

        if (ch == 10 || ch == 32 || ch ==92) 
            continue;

        //increment counter
        ar[(unsigned char)ch]++;
    }
    myFile.close();

    //sum all frequencies of characters
    int tot = 0;
    for(auto const& elem : ar)
        tot +=elem.second;

    cout << setw(5) << "Char." << setw(8) << "Freq." << setw(10) << "Prob."<<endl;
    for(const auto& elem : ar)
        if(elem.second > 0){
            cout << setw(5) << (char)elem.first
                 << setw(8) << elem.second
                 << setw(10) << fixed << setprecision(4)
                 << (double)elem.second / tot
                 << endl;
        }


        return EXIT_SUCCESS;

}

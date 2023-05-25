/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

string Process(string &query){
    map<string,string>mp;
    mp["How to connect to Airtel Xtream Wi-Fi?"] = "To connect to Airtel Xtream Wi-Fi, follow these steps:\n1. Turn on your device's Wi-Fi.";
    mp["I forgot my Wi-Fi password. What should I do?"] = "buy new router";
    mp["How to change the Wi-Fi password?"] = "dont change it...";
    mp["Why is my Wi-Fi connection slow?"] = "beacause its is slow...";
    
    string a = query;
    transform(a.begin(),a.end(),a.begin(),::tolower);
    for(auto it:mp){
        string b = it.first;
        transform(b.begin(),b.end(),b.begin(),::tolower);
        
        if(a==b){
            return it.second;
        }
    }
    
    string t = "sorry i cant found ans....\nAsk me about : \n1. how to connect to airtel Xtream\n2. why connection is slow\netc.";
    return t;
}

int main()
{
    cout << "Welcome to Airtel Xtream Wi-Fi Query Resolution!" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Ask your question (type 'Goodbye' to exit): " << endl;

    string query;
    do {
        cout << "> ";
        getline(cin, query);
        string response = Process(query);
        cout << "Response: " << response << endl;
        cout << endl;
    } while (query != "Goodbye");

    cout << "Thank you for using the Airtel Xtream Wi-Fi Query Resolution!" << endl;

    return 0;
}


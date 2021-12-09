#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


typedef int state;

//Deterministic finite automaton
class DFA{

private:

    bool locked=false;

    set<state> states;
    set<char> alphabet;
    state start;
    set<state> accept; 
    
    map<pair<state,char>,state> transition;

public:

    void read(string &filename){
        if(locked){
            cout<<"Machine is locked!"<<endl;
            return;
        }
        ifstream File(filename);
        if(!File){
            cout<<"File is not found"<<endl;
            return;
        }
        char c;
        string temp;
        while(File.get(c)){
            if(c=='\n') continue;
            temp.push_back(c);
        }
        stringstream ss(temp);
        vector<string> split; //states, alphabet, transition, start, accept 
        while(getline(ss,temp,'/')){
            split.push_back(temp); 
            cout<<temp<<endl;
        }
        File.close();

    }

    void lock(void){locked=true;}
    void unlock(void){locked=false;}

    bool run(string &word){
        state now=start;
        for(auto alphabet:word){
            pair<state,char> key={now,alphabet};
            now=transition[key];
        }   
        return accept.find(now)!=accept.end();
    }
    

};



int main(){
    DFA machine;
    string filename="test.form";
    machine.read(filename);
    while(true){

        cout<<"r (read)  q (quit) : ";

        char t; cin>>t;

        if(t=='q') break;

    }


}
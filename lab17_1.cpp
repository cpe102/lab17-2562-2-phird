#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

void grading(vector<int> &,vector<string> &);
string upper(string name){
    for(int i=0;i<name.size();i++){
        name[i]=toupper(name[i]);
    }
    return name;
}
int main(){
    ifstream file;
    string s,input;
    char format[] ="%[^:]:%d %d %d";
    vector<int> score;
    vector<string> v_name,grade;
    vector<int> calgrade;
    char name[100];
    int a,b,c;
    file.open("name_score.txt");
    //cout << "Please input your command : ";
    //cin >> input;
    while(getline(file,s)){
        sscanf(s.c_str(),format,name,&a,&b,&c);
        //cout << a << " "<<b<<" " <<c <<" "<<a+b+c<< "\n";
        v_name.push_back(name);
        calgrade.push_back(a+b+c);
        
    }
    
    file.close();
    grading(calgrade,grade);
    while(1){
        bool start =0;
        cout << "Please input your command : ";
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            s[i]=toupper(s[i]);
        }
        int idx=s.find_first_of(" ");
        string input=(s.substr(0,idx));
        string s2=(s.substr(idx+1,(s.size()-idx)));
        if(input =="NAME"){
            cout << "-------------------------------\n";
            for(int i=0;i<v_name.size();i++){
                string s3=v_name[i];
                if(upper(s3)==s2){
                    cout << v_name[i] <<"'s grade = " << grade[i]<< "\n";
                    cout << "-------------------------------\n";
                    break;
                }else if(i==v_name.size()-1) {
                    cout << "cannot found\n";
                }
            
            }
           //cout << "-------------------------------" << endl;
        }else if(input =="GRADE"){
            cout << "-------------------------------\n";
            for(int i=0;i<grade.size();i++){
                string s3=grade[i];
                if(upper(s3)==s2){
                    cout << v_name[i] << "\n";
                }
            }
            cout << "-------------------------------\n";
        }else if(input =="EXIT"){
            break;
        }else{
            cout << "Invalid command\n";   
        }
        //start =1;
    }
    

    return 0;
}

void grading(vector<int> &calgrade,vector<string> &grade){
    for(int i=0;i<calgrade.size();i++){
        if(calgrade[i]>=80){
            grade.push_back("A");
        }else if(calgrade[i]>=70){
            grade.push_back("B");
        }else if(calgrade[i]>=60){
            grade.push_back("C");
        }else if(calgrade[i]>=50){
            grade.push_back("D");
        }else{
            grade.push_back("F");
        }
    }
}



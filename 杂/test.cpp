#include<iostream>
#include<string>
using namespace std;
int main(){
    int num,op;
    string s;
    cin>>num;
    cin.get();
    (cin>>s).get();
    for(int i=0;i<num;i++){
        cin>>op;
        switch(op){
            case 1:{
                string str;
                cin>>str;
                s.append(str);
                cout<<s<<endl;
                break;
            }
            case 2:{
                int a,b;
                cin>>a>>b;
                s=s.substr(a,b);
                cout<<s<<endl;
                break;
            }
            case 3:{
                int a;
                cin>>a;
                string str;
                cin>>str;
                s.insert(a-1,str);
                cout<<s<<endl;
                break;
            }
            case 4:{
                string str;
                cin>>str;
                unsigned int index=s.find(str);
                if(index!=string::npos){
                    cout<<index<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
                break;
            }
        }
    }
    return 0;
}
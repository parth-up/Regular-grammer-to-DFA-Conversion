#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    vector<char> nts={'S','A','B'};
    vector<char> ts={'a','b'};
    char ss= 'S';
    vector<string> p={"S-aB|bB","A-a|aA","B-b"};
    
    map<char,int> mpnt;
    for(int i=0;i<nts.size();i++)
    {
        mpnt.insert({nts[i],i});
    }
    map<char,int> mpt;

    for(int i=0;i<ts.size();i++)
    {
        mpt.insert({ts[i],i});
    }

    int snts = nts.size();
    int sts = ts.size();
    int np = p.size();

    vector<vector<string>> graph(snts, vector<string>(sts,""));
    nts.push_back('F');
    
    for(int i=0;i<p.size();i++)
    {
        string s = p[i];
        int st=2;
        int pos=mpnt[s[0]];
        // cout<<s<<endl;
        while(st<s.length())
        {
            char ter=s[st];
            // cout<<ter<<endl;
            char sta;
            if(st==s.length()-1 || s[st+1]=='|')
            {
                sta='F';
                st+=2;
            }
            else
            {
                sta=s[st+1];
                st+=3;
            }
            // cout<<st<<endl;
            graph[pos][mpt[ter]] = graph[pos][mpt[ter]] + sta;
        }
    }

    
    // cout<<graph[2][0];

    cout<<"S=S"<<endl;
    cout<<"A=F"<<endl;
    cout<<"E=";
    for(int i=0;i<ts.size();i++)
    {
        if(i==ts.size()-1)
        cout<<ts[i]<<endl;
        else
        cout<<ts[i]<<",";
    }
    cout<<"Q=";
    for(int i=0;i<nts.size();i++)
    {
        if(i==nts.size()-1)
        cout<<nts[i]<<endl;
        else
        cout<<nts[i]<<",";
    }

    for(int i=0;i<snts;i++)
    {
        for(int j=0;j<sts;j++)
        {
            int l= graph[i][j].length();

            for(int k=0;k<l;k++)
            {
                cout<<nts[i]<<","<<ts[j]<<"="<<graph[i][j][k]<<endl;
            }
        }
        // cout<<endl;
    }

    return 0;
}
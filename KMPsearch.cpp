#include<bits/stdc++.h>
using namespace std;

void KMPsearch(char txt[],char pat[],int lps[],int M){
	int i=0,j=0;
	int N=strlen(txt);
	while(i<N){
		if(txt[i]!=pat[j]){
			if(j!=0)
                j=lps[j-1];
            else
                i++;
		}
		else if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==M){
			cout<<"\nPattern found at index : "<<i-j<<endl;
			j==lps[j-1];
		}
		
	}
}

void computeLPSArray(char pat[],int M,int lps[]){
	int len=0;
	lps[0]=0;
	int i=1;
	while(i<M){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len==0){
				lps[i]=0;
				i++;
			}
			else{
				len=lps[len-1];
			}
		}
	}
}

int main() 
{ 
	int N,M;
	cout<<"Enter text size : ";
	cin>>N;
	cout<<"Enter pattern size : ";
	cin>>M;
	int lps[M];
    char txt[N];
    char pat[M];
    string str_txt;
    string str_pat;
    cout<<" Enter text : ";
    cin>>str_txt;
    if(str_txt.length()>N){
    	cout<<"<<INVALID INPUT>>"<<endl;
    	return 0;
	}
    cout<<" Enter pattern : ";
    cin>>str_pat;
    if(str_pat.length()>M){
    	cout<<"<<INVALID INPUT>>"<<endl;
    	return 0;
	}
    strcpy(txt,str_txt.c_str());
    strcpy(pat,str_pat.c_str());
    computeLPSArray(pat,M,lps);
    
	KMPsearch(txt,pat,lps,M);
    return 0; 
} 

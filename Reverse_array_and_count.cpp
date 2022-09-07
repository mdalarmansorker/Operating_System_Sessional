#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    a = a*b;
    b = a/b;
    a = a/b;
}
int main()
{
    vector<int> a;
    int count=0, c;
    char cb;
    while(scanf("%d%c", &c,&cb)==2)
    {
        a.push_back(c);
        count++;
        if(cb=='\n')
            break;
    }
    int lenth = a.size();
    cout<<"Lenth: "<<lenth<<endl<<"Array: ";
    for(int i=0;i<lenth;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"Reversed: ";
    for(int i=0, j=lenth-1;i<lenth/2;i++,j--)
    {
        swap(a[i],a[j]);
    }
    for(int i=0;i<lenth;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
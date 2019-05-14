/*
Kritagya Agarwal
Contest Link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/description/
*/

#include<bits/stdc++.h>
#define ll long long int
using name std;

typedef struct trie
{
    trie * left;
    trie * right;
}trie;

trie* newnode()
{
    trie * er = new trie();
    er->left = NULL;
    er->right = NULL;
    return er;
}

void insert(ll val, trie *head)
{
    trie *temp = head;
    for(int i = 31 ; i>=0; i--)
    {
        if((1<<i) & val)
        {
            if(temp->right == NULL)
            {
                temp->right = newnode();
                temp = temp->right;
            }
            else
            {
                temp = temp->right;
            }
        }
        else
        {
            if(temp->left == NULL)
            {
                temp->left = newnode();
            }
            
            temp = temp->left;
        }
    }
}


ll findmin(trie* head,ll next)
{
    ll value = 0;
    trie *temp = head; 
    for(int i = 31 ; i>=0 ; i--)
    {
        if((1<<i) & next)
        {
            if(temp->right != NULL)
            {
                temp = temp->right;
            }
            else
            {
                value += (1<<i);
                temp = temp->left;
            }
        }
        else
        {
            if(temp->left != NULL)
            {
                temp = temp->left;
            }
            else
            {
                value += (1<<i);
                temp = temp->right;
            }
        }
    }
    
    return value;
}

int main()
{
    int q;
    cin>>q;
    ll lop = 0;
    trie*  head = newnode();
    int in = 0;
    
    insert(0,head);
    while(q--)
    {
        int t;
        cin>>t;
        if(t == 1)
        {
            ll x;
            cin>>x;
            insert(x^lop,head);
        }
        else if(t == 2)
        {
            ll x;
            cin>>x;
            lop^=x;
        }
        else
        {
            cout<<findmin(head,lop)<<endl;
        }
    }
}
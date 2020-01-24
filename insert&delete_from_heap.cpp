//MAX HEAP
#include<bits/stdc++.h>
using namespace std;
vector<int> a;

void print(int n)
{
    cout<<"\nThe heap now is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}


void deletefromheap()
{
    cout<<"\n the element that is deleted from the heap is "<<a[0];
    int parentindex  = 0;
    int leftchildindex = (2 * parentindex +1);
    int rightchildindex = (2*parentindex +2);
    if(a[leftchildindex] > a[rightchildindex])
    {
        a[parentindex] = a[leftchildindex];
        parentindex = leftchildindex;
    }

    else if(a[rightchildindex] > a[leftchildindex])
    {
        a[parentindex] = a[rightchildindex];
        parentindex  = rightchildindex;
    }

    while(1)
    {
        leftchildindex = (2 * parentindex + 1);
        rightchildindex = (2 * parentindex + 2);

        if(rightchildindex>a.size()-1)
        {
            a[parentindex] = a[leftchildindex];
            parentindex = leftchildindex;
        }

        if(leftchildindex > a.size()-1)
        {
            a[parentindex] = a[rightchildindex];
            parentindex  = rightchildindex;

        }
        if(leftchildindex > a.size()-1 || rightchildindex > a.size()-1)
            break;

        if(a[leftchildindex] > a[rightchildindex])
        {
            a[parentindex] = a[leftchildindex];
            parentindex = leftchildindex;
        }

        else if(a[rightchildindex] > a[leftchildindex])
        {
            a[parentindex] = a[rightchildindex];
            parentindex  = rightchildindex;
        }
        else
            break;

    }
    print(a.size()-1);
}
void insertheap(int ele)
{
    if(a.size() == 0)
    {
        a.push_back(ele);
    }

    else
    {
        a.push_back(ele);
        int childindex = a.size()-1;
        int parentindex = (childindex - 1)/2;

        while(1)
        {
            parentindex = (childindex - 1)/2;
            if(parentindex < 0)
            {
                break;
            }
            if( a[parentindex] < a[childindex])
            {
                //swap parent and child;
                int temp = a[parentindex];
                a[parentindex] = a[childindex];
                a[childindex] = temp;
                childindex = parentindex;
            }
            else
                break;
        }
    }
    print(a.size());
}

int main()
{
    insertheap(90);
    insertheap(75);
    insertheap(30);
    insertheap(25);
    insertheap(50);
    insertheap(95);

    deletefromheap();
    deletefromheap();
    deletefromheap();


}

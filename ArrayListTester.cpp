/**
 * A program to test the ArrayList implementation
 * @author ketsubetsu
 * <pre>
 * File: ArrayListTester.cpp
 * </pre>
 */
#include <iostream>
#include <string>
#include "ArrayList.cpp"

using namespace std;


/**
 * Displays the contents of the specified ArrayList in reverse
 * order
 * @param q - an ArrayList object
 */
template<typename ArrayListType>
void printReverseList(const ArrayList<ArrayListType>& q);

int main(int argc,char **argv)
{
   int iitem;
   ArrayList<int> intList;
   string sitem;
   ArrayList<string> stringList;
   try
   {
      if (stringList.size()==0)
         cout<<"My list is currently empty"<<endl;
      stringList.add("Jonathan");
      cout<<"'Jonathan' successfully appended."<<endl;
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;
      stringList.add("Stormy");
      cout<<"'Stormy' successfully appended."<<endl;
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;
      stringList.add("Alu");
      cout<<"'Alu' successfully appended."<<endl;
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;
      stringList.add("Michael");
      cout<<"'Michael' successfully appended."<<endl;
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;

      cout<<endl<<"Items in the list in Reverse Are: "<<endl;
      printReverseList(stringList);
      cout<<endl<<"Remove List Items: "<<endl;
      cout <<"There are "<<stringList.size()<<" items on the list."<<endl;
      while (stringList.size() != 0)
      {
         sitem = stringList.remove(0);
         cout<<sitem<<" was at the front of the list."<<endl;
      }
      if (stringList.size()==0)
         cout<<"My list is currently empty"<<endl;
      stringList.add("CSC1254");
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;
      sitem = stringList[0];
      cout<<sitem<<" is at the front of the list."<<endl;

      cout<<endl;
      if (intList.size() == 0)
         cout<<"My list is currently empty"<<endl;
      intList.add(2);
      cout<<"'2' successfully appended."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
      intList.add(3);
      cout<<"'3' successfully enqueued."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
      intList.add(5);
      cout<<"'5' successfully appended."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
      intList.add(7);
      cout<<"'7' successfully appended."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
      intList.add(11);
      cout<<"'11' successfully appended."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;

      cout<<endl<<"Items in the list in Reverse Are: "<<endl;
      printReverseList(intList);
      cout<<endl<<"Remove List Items: "<<endl;
      cout <<"There are "<<intList.size()<<" items on the list."<<endl;
      while (intList.size() != 0)
      {
         iitem = intList.remove(0);
         cout<<iitem<<" is at the front of the list."<<endl;
      }
      if (intList.size()==0)
         cout<<"My list is currently empty"<<endl;
      intList.add(13);
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
      iitem = intList[0];
      cout<<iitem<<" is at the front of the list."<<endl;
   }
   catch(ArrayListException e)
   {
      cerr<<e.what();
   }
   return 0;
}

template<typename ArrayListType>
void printReverseList(const ArrayList<ArrayListType>& q)
{
   ArrayList<ArrayListType> tmp(q);
   int i;
   try
   {
      for(i=tmp.size()-1; i >= 0; i--)
      {
         cout<<tmp[i]<<endl;
      }
   }
   catch(ArrayListException e)
   {
      cerr<<e.what();
   }
}

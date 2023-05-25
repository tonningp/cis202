#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

// Count short names with visitor
class Printer : public Visitor
{
public:    
   virtual void visit(string data);
};

void Printer::visit(string data)
{
   cout << data << " ";
}

class ShortNameCounter : public Visitor
{
public:    
   virtual void visit(string data);
   int get() const;
private:   
   int counter = 0;
};

void ShortNameCounter::visit(string data)
{
   if (data.length() <= 5) { counter++; }
}

int ShortNameCounter::get() const
{
   return counter;
}

/*
   This program demonstrates tree traversal.
*/
int main()
{
   Tree t1("1");
   Tree t2("2");
   Tree t3("3");
   Tree t4("4");
   t1.add_subtree(t2);
   t1.add_subtree(t3);
   t1.add_subtree(t4);
   Tree t2_1("5");
   Tree t2_2("6");
   Tree t2_3("7");
   t2.add_subtree(t2_1);
   t2.add_subtree(t2_2);
   t2.add_subtree(t2_3);
   Tree t3_1("8");
   Tree t3_2("9");
   t3.add_subtree(t3_1);
   t3.add_subtree(t3_2);
   t4.add_subtree(Tree("10"));
   t4.add_subtree(Tree("11"));

   cout << "Preorder: ";
   Printer v1;
   t1.preorder(v1);
   cout << endl;
   ShortNameCounter v2;
   t1.preorder(v2);
   cout << "Short names: " << v2.get() << endl;
   cout << "Postorder: ";
   t1.postorder(v1);
   cout << endl;

   // Print and count short names with breadth first iterator
   
   int counter = 0;
   cout << "Breadth first: ";
   for (BreadthFirstIterator iter = t1.begin();
        !iter.equals(t1.end()); iter.next())
   {
      string data = iter.get();
      cout << data << " ";
      if (data.length() <= 5) { counter++; }
   }
   cout << endl;
   cout << "Short names: " << counter << endl;
}

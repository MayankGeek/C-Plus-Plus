#include <iostream>
using namespace std;

class linked_list {
 private:
  class node {
   public:
    int val;
    node *next;
  };

 protected:
  node *start;

 public:
  linked_list() {
    start = NULL;
  }

  void insert(int x) {
    node *t = start;
    if (start != NULL) {
      while (t->next != NULL) {
        t = t->next;
      }
      node *n = new node;
      t->next = n;
      n->val = x;
      n->next = NULL;
    } else {
      node *n = new node;
      n->val = x;
      n->next = NULL;
      start = n;
    }
  }

  void remove(int x) {
    if (start == NULL) {
      cout << "\nLinked List is empty\n";
      return;
    } else if (start->val == x) {
      node *temp = start;
      start = start->next;
      delete temp;
      return;
    }

    node *temp = start, *parent = start;

    while (temp != NULL && temp->val != x) {
      parent = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      cout << endl
           << x << " not found in list\n";
      return;
    }

    parent->next = temp->next;
    delete temp;
  }

  void search(int x) {
    node *t = start;
    int found = 0;
    while (t != NULL) {
      if (t->val == x) {
        cout << "\nFound";
        found = 1;
        break;
      }
      t = t->next;
    }
    if (found == 0) {
      cout << "\nNot Found";
    }
  }

  void show() {
    node *t = start;
    while (t != NULL) {
      cout << t->val << "\t";
      t = t->next;
    }
  }

  void reverse() {
    node *first = start;
    node *second = first->next;
    while (second != NULL) {
      node *tem = second->next;
      second->next = first;
      first = second;
      second = tem;
    }

    start->next = NULL;
    start = first;
  }

  ~linked_list() {
    node *t = start;
    while (t->next != NULL) {
      node *tem = t->next;
      delete t;
      t = tem;
    }
    delete t;
  }
};

int main() {
  linked_list list;

  int choice, x;
  do {
    cout << "\n1. Insert";
    cout << "\n2. Delete";
    cout << "\n3. Search";
    cout << "\n4. Print";
    cout << "\n5. Reverse";
    cout << "\n0. Exit";
    cout << "\n\nEnter you choice : ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "\nEnter the element to be inserted : ";
        cin >> x;
        ;
        list.insert(x);
        break;
      case 2:
        cout << "\nEnter the element to be removed : ";
        cin >> x;
        list.remove(x);
        break;
      case 3:
        cout << "\nEnter the element to be searched : ";
        cin >> x;
        list.search(x);
        break;
      case 4:
        list.show();
        cout << "\n";
        break;
      case 5:
        cout << "The reversed list: \n";
        list.reverse();
        list.show();
        cout << "\n";
        break;
    }
  } while (choice != 0);

  return 0;
}

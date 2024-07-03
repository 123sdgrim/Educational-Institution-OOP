#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Staff
{
protected:
  int code;
  string name;

public:
  Staff(int c, string n) : code(c), name(n) {}
  int percode() { return code; }
  string pername() { return name; }
  void display()
  {
    cout << "Code: " << code << ", Name: " << name << endl;
  }
};
// Multilevel Inheritance: Staff -> Teacher
class Teacher : public Staff
{
  string subject;
  string publication;

public:
  Teacher(int c, string n, string s, string p) : Staff(c, n), subject(s), publication(p) {}
  void display1()
  {
    Staff::display();
    cout << "Subject: " << subject << ", Publication: " << publication << endl;
  }
};
// Multilevel Inheritance: Staff -> Officer
class Officer : public Staff
{
  char grade;

public:
  Officer(int c, string n, char g) : Staff(c, n), grade(g) {}
  void display1()
  {
    Staff::display();
    cout << "Grade: " << grade << endl;
  }
};
// Multilevel Inheritance: Staff -> Typist -> Regular
class Typist : public Staff
{
protected:
  int speed;

public:
  Typist(int c, string n, int s) : Staff(c, n), speed(s) {}
  void display1()
  {
    Staff::display();
    cout << "Speed: " << speed << " words per minute" << endl;
  }
};
// Hybrid Inheritance: Typist -> Regular
class Regular : public Typist
{
public:
  Regular(int c, string n, int s) : Typist(c, n, s) {}
};
// Hybrid Inheritance: Typist -> Casual
class Casual : public Typist
{
  float dailyWages;

public:
  Casual(int c, string n, int s, int w) : Typist(c, n, s), dailyWages(w) {}
  void display1()
  {
    Typist::display();
    cout << "Daily Wages: $" << dailyWages << endl;
  }
};
int main()
{
  vector<Teacher *> a;
  vector<Officer *> b;
  vector<Regular *> ct;
  vector<Casual *> d;
  cout << "Press 101 code for teacher, 201 for officer, 301 for regular typist, 401 for casual typist\n ";
      cout
       << "press -1 to end the program and 2 to see details of a staff\n";
  while (1)
  {
    int c;
    cout << "enter code\n";
    cin >> c;
    if (c == -1)
      break;
    if (c == 101)
    {
      string name, subject, topic;
      cout << "enter name:\n";
      cin >> name;
      cout << "enter subject\n";
      cin >> subject;
      cout << "enter topic\n";
      cin >> topic;
      a.push_back(new Teacher(101, name, subject, topic));
    }
    else if (c == 201)
    {
      string name;
      char grade;
      cout << "enter name:\n";
      cin >> name;
      cout << "enter grade\n";
      cin >> grade;
      b.push_back(new Officer(201, name, grade));
    }
    else if (c == 301)
    {
      string name;
      int speed;
      cout << "enter name\n";
      cin >> name;
      cout << "enter speed\n ";cin>>speed;
      ct.push_back(new Regular(301, name, speed));
    }
    else if (c == 401)
    {
      string name;
      int speed;
      float wage;
      cout << "enter name\n";
      cin >> name;
      cout << "enter speed\n";
      cin >> speed;
      cout << "enter wage\n";
      cin >> wage;
      d.push_back(new Casual(401, name, speed, wage));
    }
    else if (c == 2)
    {
      int t;
      cout << "enter code of staff\n";
      cin >> t;
      string name;
      cout << "enter name of staff\n";
      cin >> name;
      if (t == 101)
      {
        for (int i = 0; i < a.size(); i++)
        {
          if (a[i]->pername() == name)
          {
            a[i]->display1();
            cout << endl;
            break;
          }
        }
      }
      else if (t == 201)
      {
        for (int i = 0; i < b.size(); i++)
        {
          if (b[i]->pername() == name)
          {
            b[i]->display1();
            cout << endl;
            break;
          }
        }
      }
      else if (t == 301)
      {
        for (int i = 0; i < ct.size(); i++)
        {
          if (ct[i]->pername() == name)
          {
            ct[i]->display1();
            cout << endl;
            break;
          }
        }
      }
      else if (t == 401)
      {
        for (int i = 0; i < d.size(); i++)
        {
          if (d[i]->pername() == name)
          {
            d[i]->display1();
            cout << endl;
            break;
          }
        }
      }
      else
        cout << "invalid code\n";
    }
    else
    {
      cout << "invalid code\n";
    }
  }
  return 0;
}

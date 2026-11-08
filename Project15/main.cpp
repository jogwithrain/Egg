#include <iostream>
#include <vector>
using namespace std;


class Egg {
protected:
    string flavor;
    double size;
public:
    Egg(string _f, double _s) {
        flavor = _f;
        size = _s;
    }
    virtual void eat_egg() = 0;
};
class boiled_egg :public Egg {
protected:

public:
    boiled_egg(double s) :Egg("boiled", s) {}
    void eat_egg() {
        cout << "You eat a boiled egg" << endl;
    }
};
class scramble_egg :public Egg {
protected:

public:
    scramble_egg(double s) :Egg("scramble", s) {}
    void eat_egg() {
        cout << "You eat a scrambled egg" << endl;
    }
};
class bad_egg :public Egg {
protected:

public:
    bad_egg(double s) :Egg("bad", s) {}
    void eat_egg() {
        throw "There was a Bad Egg.";
    }
};
class rotten_egg :public bad_egg {
protected:

public:
    rotten_egg(double s) :bad_egg(s) {}

};
class Carton {
protected:
    vector<Egg*> carton;
public:

    void add_to_list(Egg* v) {
        carton.push_back(v);
    }
    void check_egg() {
        auto start = carton.begin();
        auto end = carton.end();
        if (start != end) {
            try {
                (*start)->eat_egg();
            }
            catch (const char* e) {
                cout << e << " This will be removed." << endl;
            }
            carton.erase(carton.begin());
        }
    }
};
int main()
{
    boiled_egg a = boiled_egg(2.0);
    rotten_egg b = rotten_egg(1.5);
    boiled_egg t = boiled_egg(2.3);
    scramble_egg l = scramble_egg(3.5);
    bad_egg c = bad_egg(2.1);

    Carton e = Carton();
    e.add_to_list(&a); //Boilded egg
    e.add_to_list(&b); //rotten
    e.add_to_list(&t); //boilded
    e.add_to_list(&l); //scramble
    e.add_to_list(&c); //bad

    e.check_egg();
    e.check_egg();
    e.check_egg();
    e.check_egg();
    e.check_egg();
    e.check_egg(); //Extra one which prints nothing.
}
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <map>
using namespace std;


class Sotrudnik //Базовый класс сотрудник

        {

public: //Доступ для наследования


    const string &getFio() const {
        return FIO;
    }

    void setFio(const string &fio) {
        FIO = fio;
    }

    int getZarplata() const {
        return Zarplata;
    }

    void setZarplata(int zarplata) {
        Zarplata = zarplata;
    }

    const string &getPost() const {
        return post;
    }

    void setPost(const string &post) {
        Sotrudnik::post = post;
    }


    void display(){
        cout<<"FIO: "<<FIO<<" Post: "<<post<<" Salary = "<<Zarplata<<endl;
    }
    void checkDannie(){
        string fio;
        checkFIO:
        cout<<"Insert FIO\n> ";
        regex v("([A-Z][a-z]+[\\-\\s]?){3,}");
        getline(cin,fio);
        if (regex_match(fio,v)) {
            FIO=fio;
        }
        else {
            cout<<"Wrong format of FIO\n";
            goto checkFIO;
        }

        int salary;

        checkSalary:
        cout<<"Insert salary\n> ";
        cin>>salary;
        if (!cin or salary<=0){
            cout <<"Wrong format of salary\n";
            cin.clear();

            goto checkSalary;

        }
        else Zarplata=salary;


}


private:
    string FIO; //Строковое значаение Фио
    int Zarplata; // Целое числол зарплата
    string post;
};

class Direktor : public Sotrudnik{
private:
    vector<Sotrudnik> sotrudniki;


public:
    const vector<Sotrudnik> &getSotrudniki() const {
        return sotrudniki;
    }

    void setSotrudniki(const vector<Sotrudnik> &sotrudniki) {
        Direktor::sotrudniki = sotrudniki;
    }

    void dismiss(string FIO){ //увольнение
        bool isFind=false;
        for (int i=0;i<sotrudniki.size();i++){
            if(sotrudniki[i].getFio()==FIO){
                isFind= true;
                sotrudniki.erase(sotrudniki.begin()+i);

            }

        }
        if (isFind==false){
            cout<<"Employee not find\n";
        }




    }
     void accept(Sotrudnik sotrudnik){
                sotrudniki.push_back(sotrudnik);


    }
//    void display(Direktor direktor){
//        cout<<"Директор-";
//        direktor.Sotrudnik::display(direktor);
//        cout<<endl;
//    }


};
class Buhgalter: public Sotrudnik{
private:
    map<string,int> stavka;

public:

    const map<string, int> &getStavka() const {
        return stavka;
    }

    void setStavka() {
        Buhgalter::stavka["Director"]=1000;
        Buhgalter::stavka["Buhgalter"]=400;
        Buhgalter::stavka["Programmist"]=600;
        Buhgalter::stavka["SysAdmin"]=500;
    }

    void raschet(string s,int hours){

        cout<<"Salary for "<<s<<" = "<<stavka[s]*hours<<endl;



    }
//    void display(Buhgalter buhgalter) {
//        cout << "Бухгалтер-";
//        buhgalter.Sotrudnik::display(buhgalter);
//        cout << " ";
//
//    }




};
class SysAdmin: public Sotrudnik{
private:
    vector<string> oborudovanie;

public:
    const vector<string> &getOborudovanie() const {
        return oborudovanie;
    }

    void setOborudovanie(const vector<string> &oborudovanie) {
        SysAdmin::oborudovanie = oborudovanie;
    }

};

class Programmist: public Sotrudnik{
private:
    string level;
    vector<string> skills;

public:
    const string &getLevel() const {
        return level;
    }

    void setLevel(const string &level) {
        Programmist::level = level;
    }

    const vector<string> &getSkills() const {
        return skills;
    }

    void setSkills(const vector<string> &skills) {
        Programmist::skills = skills;
    }
//    void display(Programmist programmist) {
//        cout<<"Программист-";
//        programmist.Sotrudnik::display(programmist);
//        cout<<" Уровень программиста:"<< programmist.getLevel()<<" Его скиллы:";
//        programmist.setSkills({"HTML", "JAVA", "Flask"});
//        for(string skill:programmist.getSkills()){
//            cout<<skill<<" ";
//        }
//        cout<<endl;

    };
class deathDiamond: public Programmist, SysAdmin{

};

class Initsiali{
private:
    string initsiali;
public:
    const string &getInitsiali() const {
        return initsiali;
    }

    void setInitsiali(const string &initsiali) {
        Initsiali::initsiali = initsiali;
    }
    void displayinit(string f, string i, string o){
        cout<<"Initsials: "<<f<<" "<<i[0]<<"."<<o[0]<<".\n";
    }

};
class Viplati{
private:
    vector<int> viplati;
public:
    const vector<int> &getViplati() const {
        return viplati;
    }

    void setViplati(const vector<int> &viplati) {
        Viplati::viplati = viplati;
    }

};
class Svedenia:public Initsiali, public Viplati{


};

int main() {


//    deathDiamond deathDiamond;
//    deathDiamond.display();

int i;
int j;
ex:
    cout<<"Chose exercise\n"
          "1. 1.1\n"
          "2. 1.2\n"
          "3. exit\n";
    cin>>i;
    if (!cin or i<1 or i>3){
        cout<<"Wrong number\n";
        goto ex;
    }
    if (i==1) {
        cin.get();
        cout << "Let start with create the director\n";
        Direktor *d = new Direktor;
        Buhgalter b;
        Programmist p;
        SysAdmin s;
        d->setPost("Director");
        d->checkDannie();
        d->display();

        cout << "Now U can create another employyes\n";
        chose:
        bool existB = false;
        bool existP = false;
        bool existS = false;
        for (Sotrudnik e: d->getSotrudniki()) {
            string post = e.getPost();
            if (post == "Buhgalter") existB = true;
            if (post == "Programmist") existP = true;
            if (post == "Sysadmin") existS = true;
        }
        if (existB == false and existP == false and existS == false) {

            cout << "Chose post what you want to create.\n"
                    "1.Buhgalter\n"
                    "2.Programmist\n"
                    "3.SysAdmin\n"
                    "4.Back to chose ex\n";
        }
        if (existB == true and existP == false and existS == false) {
            cout << "Chose post what you want to create.\n"
                    "2.Programmist\n"
                    "3.SysAdmin\n"
                    "4.Back to chose ex\n";
        }
        if (existB == true and existP == true and existS == false) {

            cout << "Chose post what you want to create.\n"
                    "3.SysAdmin\n"
                    "4.Back to chose ex\n";
        }
        if (existB == true and existP == true and existS == true) {

            cout << "Chose post and check it\'s functions.\n"
                    "1.Buhgalter\n"
                    "2.Programmist\n"
                    "3.SysAdmin\n"
                    "4.Director\n"
                    "5.Back to chose ex\n";
            cin >> j;
            goto functions;

        }

        if (existB == false and existP == true and existS == false) {

            cout << "Chose post what you want to create.\n"
                    "1.Buhgalter\n"
                    "3.SysAdmin\n"
                    "4.Back to chose ex\n";
        }
        if (existB == false and existP == true and existS == true) {

            cout << "Chose post what you want to create.\n"
                    "1.Buhgalter\n"
                    "4.Back to chose ex\n";

        }
        if (existB == true and existP == false and existS == true) {
            cout << "Chose post what you want to create.\n"
                    "2.Programmist\n"
                    "4.Back to chose ex\n";
        }


        cin >> i;
        if (!cin or i < 1 or i > 4) {
            cout << "Input error\n";
            goto chose;
        } else {
            switch (i) {

                case 1: {
                    cin.get();
                    b.setPost("Buhgalter");
                    b.checkDannie();
                    b.display();
                    b.setStavka();
                    vector<Sotrudnik> temp = d->getSotrudniki();
                    temp.push_back(b);
                    d->setSotrudniki(temp);
                    goto chose;

                }
                case 2: {
                    cin.get();
                    p.setPost("Programmist");
                    p.checkDannie();
                    p.display();
                    vector<Sotrudnik> temp = d->getSotrudniki();
                    temp.push_back(p);
                    d->setSotrudniki(temp);
                    goto chose;
                }
                case 3: {
                    cin.get();
                    s.setPost("Sysadmin");
                    s.checkDannie();
                    s.display();
                    vector<Sotrudnik> temp = d->getSotrudniki();
                    temp.push_back(s);
                    d->setSotrudniki(temp);
                    goto chose;
                }
                case 4:
                    cin.get();
                    goto ex;

            }
        }
        functions:
        switch (j) {
            case 1: {
                map<string, int> temp = b.getStavka();
                buh:
                cout << "Buhgalter can calculate salary for each post\n"
                        "Chose post what you want to calculate\n"
                        "1. Director\n"
                        "2. Programmist\n"
                        "3. Buhgalter\n"
                        "4. SysAdmin\n"
                        "5. Back\n";
                int c;
                cin >> c;
                if (!cin or c < 1 or c > 5) {
                    cout << "Wrong number\n";
                    goto buh;
                }
                switch (c) {
                    case 1: {

                        cout << "Bid for director is " << temp["Director"] << "per hour\n"
                                                                              "Insert hours for calculating\n>";
                        int h;
                        cin >> h;
                        b.raschet("Director", h);
                        goto buh;


                        case 2:
                            cout << "Bid for Programmist is " << temp["Programmist"] << "per hour\n"
                                                                                        "Insert hours for calculating\n>";

                        cin >> h;
                        b.raschet("Programmist", h);
                        goto buh;
                        case 3:
                            cout << "Bid for buhgalter is " << temp["Buhgalter"] << "per hour\n"
                                                                                    "Insert hours for calculating\n>";
                        cin >> h;
                        b.raschet("Buhgalter", h);
                        goto buh;
                        case 4:
                            cout << "Bid for sysadmin is " << temp["SysAdmin"] << "per hour\n"
                                                                                  "Insert hours for calculating\n>";

                        cin >> h;
                        b.raschet("SysAdmin", h);
                        goto buh;
                        case 5:
                            goto chose;

                    }
                }
            }


            case 2: {
                //programmist functions
                prog:
                cout << "There are many functions of Programmist:\n"
                        "1. Insert Level of programmist\n"
                        "2. Show Level of programmist\n"
                        "3. Insert stack of Technology\n"
                        "4. Show stack of Technology\n"
                        "5. Back\n"
                        "Insert number of function\n>";
                int f;
                cin >> f;
                if (!cin or f < 1 or f > 5) {
                    cout << "Wrong number\n";
                    goto prog;
                }
                switch (f) {
                    case 1: {
                        level:
                        cout << "Insert level of programmist. For example: Junior, Middle, Senior\n";
                        string l;
                        cin >> l;
                        if (l != "Junior" or l != "Middle" or l != "Senior") {
                            cout << "This level not exists\n";
                            goto level;
                        } else p.setLevel(l);
                    }
                    case 2: {
                        cout << "The level of programmist is " << p.getLevel() << endl;
                        goto prog;

                    }
                    case 3: {
                        ins:
                        cout << "Insert number of Skills\n>";
                        int x;
                        cin >> x;
                        if (!cin or x <= 0) {
                            cout << "Wrong number";
                            goto ins;
                        }
                        vector<string> tempskills = p.getSkills();
                        for (int q = 0; q < x; q++) {
                            cout << "Insert skill\n";
                            string sk;
                            cin >> sk;
                            tempskills.push_back(sk);


                        }
                        p.setSkills(tempskills);
                        goto prog;

                    }
                    case 4: {
                        cout << "Stack of technology:\n";
                        for (string g: p.getSkills()) {
                            cout << g << endl;
                        }
                        goto prog;
                    }
                    case 5: {
                        goto chose;
                    }

                }

                goto chose;
            }
            case 3: {
                sys:
                cout << "Sysadmin have oly two functions:\n"
                        "1. Insert equipment\n"
                        "2. Show equipment\n"
                        "3. Back\n"
                        "Insert number\n";
                int w;
                cin >> w;
                if (!cin or w < 1 or w > 3) {
                    cout << "Wrong number\n";
                    goto sys;
                }
                switch (w) {
                    case 1: {
                        eq:
                        cout << "Insert number of equipment\n";
                        int e;
                        cin >> e;
                        if (!cin or e <= 0) {
                            cout << "Wrong number\n";
                            goto eq;
                        }
                        vector<string> tempeq = s.getOborudovanie();
                        for (int r = 0; r < e; r++) {
                            cout << "Insert equipment\n";
                            string eqq;
                            cin >> eqq;
                            tempeq.push_back(eqq);
                        }
                        s.setOborudovanie(tempeq);
                        goto sys;
                    }
                    case 2:
                        cout << "Equipment:\n";
                        for (string t: s.getOborudovanie()) {
                            cout << t << endl;
                        }
                        goto sys;
                    case 3:
                        goto chose;
                }
                //sysadmin
                goto chose;
            }
            case 4: {
                //director
                dir:
                cout << "Functions of direktor:\n"
                        "1. Show employes and their\'s salary\n"
                        "2. Fire employee\n"
                        "3. Hire employee\n"
                        "4. Back\n"
                        "Insert number\n>";
                int y;
                cin >> y;
                if (!cin or y < 1 or y > 4) {
                    cout << "Wrong number\n";
                    goto dir;
                }
                switch (y) {
                    case 1: {
                        cout << "Employe\'s name, his salary and post\n";
                        for (Sotrudnik u: d->getSotrudniki()) {
                            u.display();
                        }
                        goto dir;
                    }
                    case 2: {
                        cout << "Inser FIO of employee you want to fire\n";
                        string o;
                        cin.get();
                        getline(cin, o);
                        d->dismiss(o);
                        goto dir;
                    }
                    case 3: {
                        cout << "Now u can hire a new employe\n";
                        Sotrudnik sotrudnik;
                        cin.get();
                        sotrudnik.checkDannie();
                        vector<Sotrudnik> temps = d->getSotrudniki();
                        temps.push_back(sotrudnik);
                        d->setSotrudniki(temps);
                        goto dir;
                    }
                    case 4: {
                        goto chose;
                    };
                }
                case 5:
                    cin.get();
                    goto ex;
            }
        }
    }
    else if (i==2) {
        ex2:
        Svedenia svedenia;
        cout << "Create class svedenia\n"
                "Insert Surname\n";
        string f;
        cin>>f;
        cout<<"Insert name\n";
        string n;
        cin>>n;
        cout<<"Insert MiddleName\n";
        string o;
        cin>>o;
        svedenia.displayinit(f,n,o);
        cout<<"Insert number of payments\n";
        int p;
        cin>>p;
        vector<int> temppayment=svedenia.getViplati();
        for (int l=0;l<p;l++){
            cout<<"Insert payement\n";
            int p1;
            cin>>p1;
            temppayment.push_back(p1);

        }
        svedenia.setViplati(temppayment);
        cout<<"List of payments:\n";
        for (int g:svedenia.getViplati()){
            cout<<g<<endl;
        }
        return 0;



    } else if( i==3){
        return 0;
    }



    return 0;
}

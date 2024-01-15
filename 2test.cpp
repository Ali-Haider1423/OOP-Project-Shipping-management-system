#include <iostream>
#include <string>
#include <limits>
using namespace std;
class User
{
protected:
    string name;
    string gender;
    int age;

public:
    User(){};
    virtual void Set_name(string n) = 0;
    virtual void Set_gender(string n) = 0;
    virtual void Set_age(int n) = 0;
    virtual string Get_name() = 0;
    virtual string Get_gender() = 0;
    virtual int Get_age() = 0;
};
class management : private User
{
private:
    string adminuser = "ali";
    string adminpass = "ali";
    int cnic;
    string username;
    string password;

public:
    management(){};
    void Set_name(string n);
    void Set_gender(string n);
    void Set_age(int n);
    void Set_cnic(int n);
    void Set_username(string n);
    void Set_password(string n);
    string Get_name();
    string Get_gender();
    int Get_age();
    int Get_cnic();
    string Get_username();
    string Get_password();
    string Get_adusername();
    void Creataccount();
    void loginaccount(string user, string pass);
    void display_available_management();
};
class ycustomer : private User
{
private:
    string Permanant_adress;
    string Current_location;
    long long phone_number;
    float advance_payment;

public:
    ycustomer(){};
    void Set_name(string n);
    void Set_gender(string n);
    void Set_age(int n);
    string Get_name();
    string Get_gender();
    int Get_age();
    void Set_permanent_adress(string n);
    void Set_current_location(string n);
    void Set_phone_number(int n);
    void Set_advance_payment(float n);
    string get_permanent_adress();
    string get_current_location();
    int get_phone_number();
    float get_advance_payment();
    friend ostream &operator<<(ostream &out, ycustomer &c)
    {
        cout << "\n\t\t------------------------------------------" << endl;
        cout << "\t\tName: " << c.name << endl;
        cout << "\t\tgender: " << c.gender << endl;
        cout << "\t\tage: " << c.age << endl;
        cout << "\t\tPermanent_adress: " << c.Permanant_adress << endl;
        cout << "\t\tCurrent_location: " << c.Current_location << endl;
        cout << "\t\tphone_number: " << c.phone_number << endl;
        cout << "\t\t------------------------------------------" << endl;
    }
    friend istream &operator>>(istream &in, ycustomer &c)
    {
        cout << endl;
        cout << "\t\tEnter your name: ";
        in >> c.name;
        cout << "\t\tEnter your gender: ";
        in >> c.gender;
        cout << "\t\tEnter your age: ";
        while (!(in >> c.age))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cout << "\t\tEnter your Permanent adress: ";
        in >> c.Permanant_adress;
        cout << "\t\tEnter your Current location: ";
        in >> c.Current_location;
        cout << "\t\tEnter your phone number: ";
        while (!(in >> c.phone_number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
    }
};
class boat
{
protected:
    string make;
    int model;
    string varient;

public:
    boat(){};
};
class Itravels
{
protected:
    string country;
    float firstclass_price, bussisness_price, economy_price;
    int dep_dd, dep_mm, dpe_yyyy;
    int arv_dd, arv_mm, arv_yyyy;
    int remaining_tickets;
    int Id, bought_tickets;

public:
    void set_id(int n)
    {
        Id = n + 1;
    }
    int get_id()
    {
        return Id;
    }
    int get_classprice(int n)
    {
        if (n == 1)
        {
            return firstclass_price;
        }
        else if (n == 2)
        {
            return bussisness_price;
        }
        else if (n == 3)
        {
            return economy_price;
        }
    }
    void set_country(string c);
    void set_firstclass_price(float n);
    void set_bussisness_price(float n);
    void set_economy_price(float n);
    void set_dep_date(int d, int m, int y);
    void set_arv_date(int d, int m, int y);
    void set_remaning_tickets(int n = 0)
    {
        remaining_tickets -= n;
    }
    friend istream &operator>>(istream &in, Itravels &I)
    {
        cout << "\n\t\tEnter the destination country: ";
        in >> I.country;
        cout << "\n\t\tEnter the Frist class ticket price: ";
        while (!(in >> I.firstclass_price))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cout << "\n\t\tEnter Bussisness class ticket price: ";
        while (!(in >> I.bussisness_price))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cout << "\n\t\tEnter Economy class ticket price: ";
        while (!(in >> I.economy_price))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }

        do
        {
            cout << "\n\t\tEnter departure day: ";
            while (!(in >> I.dep_dd))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.dep_dd < 1 || I.dep_dd > 31)
            {
                cout << "\n invalid day:";
            }
        } while (I.dep_dd < 1 || I.dep_dd > 31);

        do
        {
            cout << "\n\t\tEnter departure month: ";
            while (!(in >> I.dep_mm))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.dep_mm < 1 || I.dep_mm > 12)
            {
                cout << "\n invalid month:";
            }
        } while (I.dep_mm < 1 || I.dep_mm > 12);

        do
        {
            cout << "\n\t\tEnter departure year: ";
            while (!(in >> I.dpe_yyyy))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.dpe_yyyy < 2024 || I.dpe_yyyy > 2028)
            {
                cout << "\n invalid year:";
            }
        } while (I.dpe_yyyy < 2024 || I.dpe_yyyy > 2028);

        do
        {
            cout << "\n\t\tEnter arival day: ";
            while (!(in >> I.arv_dd))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.arv_dd < 1 || I.arv_dd > 31)
            {
                cout << "\n invalid day:";
            }
        } while (I.arv_dd < 1 || I.arv_dd > 31);

        do
        {
            cout << "\n\t\tEnter arival month: ";
            while (!(in >> I.arv_mm))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.arv_mm < 1 || I.arv_mm > 12)
            {
                cout << "\n invalid month:";
            }
        } while (I.arv_mm < 1 || I.arv_mm > 12);

        do
        {
            cout << "\n\t\tEnter arival year: ";
            while (!(in >> I.arv_yyyy))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (I.arv_yyyy < 2024 || I.arv_yyyy > 2028)
            {
                cout << "\n invalid yaer:";
            }
        } while (I.arv_yyyy < 2024 || I.arv_yyyy > 2028);

        cout << "Enter total available tickets: ";
        in >> I.remaining_tickets;
    }
    friend ostream &operator<<(ostream &out, Itravels &I)
    {
        cout << I.Id << "             " << I.country << "              " << I.firstclass_price << "                      " << I.bussisness_price << "                    " << I.economy_price << "          "
             << "(" << I.dep_dd << " , " << I.dep_mm << " , " << I.dpe_yyyy << ")"
             << "      "
             << "(" << I.arv_dd << " , " << I.arv_mm << " , " << I.arv_yyyy << ")          " << I.remaining_tickets << endl;
    }
};
class Ibookings : private Itravels
{
private:
    int flag = 0;
    string name, status;
    int age;
    string gender;
    string Permanant_adress;
    string Current_location;
    int phone_number;
    long long cardnumber;
    int expdate, cvc;
    char choice;
    int booked_tickets;

public:
    void set_payment();
    void set_booked_tickets(int n)
    {
        booked_tickets = n;
    }
    friend ostream &operator<<(ostream &out, Ibookings &I)
    {
        cout << "\n\t\t------------------------------------------" << endl;
        cout << "\t\tName: " << I.name << endl;
        cout << "\t\tPayment status: " << I.status << endl;
        cout << "\t\tTotal booked Tickets: " << I.booked_tickets << endl;
        cout << "\t\tgender: " << I.gender << endl;
        cout << "\t\tage: " << I.age << endl;
        cout << "\t\tPermanent_adress: " << I.Permanant_adress << endl;
        cout << "\t\tCurrent_location: " << I.Current_location << endl;
        cout << "\t\tphone_number: " << I.phone_number << endl;
        cout << "\t\t------------------------------------------" << endl;
    }
    friend istream &operator>>(istream &in, Ibookings &c)
    {
        cout << endl;
        cout << "\t\tEnter your name: ";
        in >> c.name;
        cout << "\t\tEnter your gender: ";
        in >> c.gender;
        cout << "\t\tEnter your age: ";
        while (!(in >> c.age))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cout << "\t\tEnter your Permanent adress: ";
        in >> c.Permanant_adress;
        cout << "\t\tEnter your Current location: ";
        in >> c.Current_location;
        cout << "\t\tEnter your phone number: ";
        in >> c.phone_number;
        c.set_payment();
        if (c.flag == 0)
        {
            c.status = "unpaid";
        }
        else if (c.flag == 1)
        {
            c.status = "Paid";
        }
    }
};
class cargo_ship
{
private:
    int weight, cnic, payment = 1000;
    string destination, name;
    int id;

public:
    cargo_ship(){};
    void set_id(int n)
    {
        id = n + 1;
    }
    int get_id()
    {
        return id;
    }
    friend ostream &operator<<(ostream &out, cargo_ship &c)
    {
        cout << "\n\t\t\t--------------------" << endl;
        cout << "\t\t\tShipment ID: " << c.id << endl;
        cout << "\t\t\tName: " << c.name << endl;
        cout << "\t\t\tCNIC: " << c.cnic << endl;
        cout << "\t\t\tWeight: " << c.weight << "kg" << endl;
        cout << "\t\t\tTotal bill: " << c.payment << "PKR." << endl;
        cout << "\t\t\tDestination: " << c.destination << endl;
        cout << "\t\t\t--------------------" << endl;
    }
    friend istream &operator>>(istream &in, cargo_ship &c)
    {
        cout << "\n\t\tEnter your name: ";
        cin >> c.name;
        cout << "\t\tEnter your CNIC: ";
        while (!(in >> c.cnic))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cout << "\t\tEnter weight of shipment in kg: ";
        while (!(in >> c.weight))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        c.payment *= c.weight;
        cout << "\t\tEnter destination: ";
        cin >> c.destination;
    }
};
class yatch : protected boat
{
private:
    int id;
    int flag = 0;
    float per_day_rent;
    int size;        // In feets and inches
    string design;   // Modern, classic, expedition, or custom design styles.
    string Material; // Common materials include fiberglass, aluminum, steel, or a combination
    int speed;       // in KMPH
    int Crew_Capacity;
    string Flag_and_Registration; // The country under whose flag the yacht is registered.
    int dd, mm, yyyy;

public:
    yatch(){};
    void set_flag(int n);
    int get_flag();
    void set_id(int n);
    int get_id();
    void set_make(string n);
    void set_pdr(float n);
    void set_model(int n);
    void set_varient(string n);
    void set_size(int n);
    void set_design(string n);
    void set_material(string n);
    void set_speed(int n);
    void set_crew_capacity(int n);
    void set_Flag_and_Registration(string n);
    string get_make();
    int get_model();
    string get_varient();
    void set_date(int n, int m, int p);
    int get_day();
    int get_mm();
    int get_yyyy();

    friend ostream &operator<<(ostream &out, yatch &y)
    {
        cout << "\n\t\t\t--------------------------------------------------" << endl;
        cout << "\t\t\tYatch Id: " << y.id << endl;
        if (y.flag == 1)
        {
            cout << "\t\t\tStatus: Yacht is booked for (" << y.dd << " , " << y.mm << " , " << y.yyyy << ")" << endl;
        }
        else
        {
            cout << "\t\t\tStatus: available for all dates..." << endl;
        }
        cout << "\t\t\tMake: " << y.make << endl;
        cout << "\t\t\tModel: " << y.model << endl;
        cout << "\t\t\tVarient: " << y.varient << endl;
        cout << "\t\t\tPer day rent: " << y.per_day_rent << endl;
        cout << "\t\t\tDize: " << y.size << endl;
        cout << "\t\t\tDesign: " << y.design << endl;
        cout << "\t\t\tMaterial: " << y.Material << endl;
        cout << "\t\t\tSpeed: " << y.speed << endl;
        cout << "\t\t\tCrew_Capacity: " << y.Crew_Capacity << endl;
        cout << "\t\t\tFlag and Registration: " << y.Flag_and_Registration << endl;
        cout << "\t\t\t--------------------------------------------------" << endl;
    }
};

int i = 0;
int count = 0;
int yc = 0, cc = 0, It = 0, IB = 0, cargo = 0;

int main()
{
    int flag;
    int opt;
    char choice;

    management m[10];
    string user, pass;

    yatch y[100];
    int size, speed, Crew_Capacity, model;
    string design, Material, Flag_and_Registration, discription, make, varient;
    float per_day_rent;
    int bid, dd, mm, yyyy;

    ycustomer c[100];
    Itravels I[100];
    Ibookings IBk[100];
    int count_ticket;

    cargo_ship crg[100];

    do
    {
        system("cls");
        cout << "\t       ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t       |                                                                                                                                     |" << endl;
        cout << "\t       |                      ******************Welcome to Ships reservation and management system******************                         |" << endl;
        cout << "\t       |                                                                                                                                     |" << endl;
        cout << "\t       ---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "\t\t                    ----------------------------------------------" << endl;
        cout << "\t\t                   |                                              |" << endl;
        cout << "\t\t                   |   1). Management login                       |" << endl;
        cout << "\t\t                   |   2). Internamional Travels                  |" << endl;
        cout << "\t\t                   |   3). Private Reservations                   |" << endl;
        cout << "\t\t                   |   4). cargo shipments                        |" << endl;
        cout << "\t\t                   |                                              |" << endl;
        cout << "\t\t                    ----------------------------------------------" << endl;
        cout << "\n\t\t                   Enter your option or press 5 to qxit...";
        while (!(cin >> opt))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        switch (opt)
        {
        case 1:
            do
            {
                system("cls");

                cout << "\n\t\t\t------------------------------------------" << endl;
                cout << "\t\t\t*****Welcome to management login page*****" << endl;
                cout << "\t\t\t------------------------------------------" << endl;
                cout << "1).Login to existing account" << endl;
                cout << "2).Create an account" << endl;
                cout << "3).Details of available Officers" << endl;
                cout << "Enter your option or press 4 to exit...";
                while (!(cin >> opt))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter an integer: ";
                }
                switch (opt)
                {
                case 1:
                    system("cls");
                    cout << "\n\t\t\t---------------------" << endl;
                    cout << "\t\t\tWelcome to login page" << endl;
                    cout << "\t\t\t---------------------" << endl;

                    cout << "\t\tEnter your username: ";
                    cin >> user;
                    cout << "\n\t\tEnter your password: ";
                    cin >> pass;
                    for (int i = 0; i < count; i++)
                    {
                        if (user == m[i].Get_username() && pass == m[i].Get_password())
                        {
                            m[i].loginaccount(user, pass);
                            break;
                        }
                    }
                    break;
                case 2:
                    m[i].Creataccount();
                    i++;
                    count++;
                    break;
                case 3:
                    system("cls");
                    cout << "\n\t\t\t---------------------------------------" << endl;
                    cout << "\t\t\t******management officers details******" << endl;
                    cout << "\t\t\t---------------------------------------" << endl;
                    do
                    {
                        for (int i = 0; i < count; i++)
                        {
                            m[i].display_available_management();
                        }
                        cout << "\t\tPress 'q' to exit...";
                        cin >> choice;
                    } while (choice != 'q');

                    break;
                }
            } while (opt != 4);

            break;
        case 2:
            do
            {
                system("cls");
                cout << "\n\t\t\t------------------------------------------" << endl;
                cout << "\t\t\t*******international travle bookings*******" << endl;
                cout << "\t\t\t-------------------------------------------" << endl;
                cout << "1).Add a new Destination" << endl;
                cout << "2).Book a ticket " << endl;
                cout << "3).details of all customers" << endl;
                cout << "Enter your option or press 4 to exit...";
                while (!(cin >> opt))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter an integer: ";
                }
                switch (opt)
                {
                case 1:
                    system("cls");
                    cout << "\n\n\t\t\t---------------------" << endl;
                    cout << "\t\t\tWelcome to login page" << endl;
                    cout << "\t\t\t---------------------" << endl;

                    cout << "\t\tEnter your username: ";
                    cin >> user;
                    cout << "\n\t\tEnter your password: ";
                    cin >> pass;
                    for (int i = 0; i < count; i++)
                    {
                        if (user == m[i].Get_username() && pass == m[i].Get_password())
                        {
                            system("cls");
                            cout << "\n\n\t\t\t-------------------------" << endl;
                            cout << "\t\t\t***Add new Destination***" << endl;
                            cout << "\t\t\t-------------------------" << endl;
                            cout << "\n\t\tEnter details of new destination..." << endl;
                            cin >> I[It];
                            I[It].set_id(It);
                            It++;
                        }
                    }
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        cout << "\n\t\t\t\t\t------------------------------------------" << endl;
                        cout << "\t\t\t\t\t*******Upcomming avalible Departures*******" << endl;
                        cout << "\t\t\t\t\t-------------------------------------------" << endl;
                        cout << "\n\nBooking Id    Country        First Class Ticket      Bussisness class Ticket      Economy Ticket       Departure date        Arival Date      remaning Tickets" << endl;

                        for (int i = 0; i < It; i++)
                        {
                            cout << I[i];
                        }
                        cout << "\n\n\t1)Book a Ticket" << endl;
                        cout << "\t2)Bookings summery" << endl;
                        cout << "\t3)Back to main menue..." << endl;

                        cout << "\nSelect your option...";
                        while (!(cin >> opt))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter an integer: ";
                        }
                        switch (opt)
                        {
                        case 1:
                            cout << "\n\n\t\t\tEnter booking ID: ";
                            while (!(cin >> bid))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            cout << "\t\tEnter number of tickets you want to buy: ";
                            cin >> count_ticket;
                            // IBk[IB].set_paid_ammount();
                            IBk[IB].set_booked_tickets(count_ticket);
                            I[bid - 1].set_remaning_tickets(count_ticket);
                            for (int i = 0; i < It; i++)
                            {
                                if (bid == I[i].get_id())
                                {
                                    cout << "\t\tEnter your details...";
                                    cin >> IBk[IB];
                                    IB++;
                                }
                            }
                            break;
                        case 2:
                            do
                            {
                                system("cls");
                                cout << "\n\t\t\t\t\t------------------------------------------" << endl;
                                cout << "\t\t\t\t\t**********Bookings summery Report**********" << endl;
                                cout << "\t\t\t\t\t-------------------------------------------" << endl;
                                for (int i = 0; i < IB; i++)
                                {
                                    cout << IBk[i];
                                }
                                cout << "\n\tPress 'q' to exit...";
                                cin >> choice;
                            } while (choice != 'q');
                            break;
                        }
                    } while (opt != 3);
                    break;
                case 3:
                    do
                    {
                        system("cls");
                        cout << "\n\t\t\t\t\t------------------------------------------" << endl;
                        cout << "\t\t\t\t\t**********Bookings summery Report**********" << endl;
                        cout << "\t\t\t\t\t-------------------------------------------" << endl;
                        for (int i = 0; i < IB; i++)
                        {
                            cout << IBk[i];
                        }
                        cout << "\n\tPress 'q' to exit...";
                        cin >> choice;
                    } while (choice != 'q');
                    break;
                }
            } while (opt != 4);
            break;
        case 3:
            do
            {
                system("cls");
                cout << "\t\t\t--------------------------" << endl;
                cout << "\t\t\t***Private reservations***" << endl;
                cout << "\t\t\t--------------------------" << endl;
                cout << "\n1). Add a new yatch" << endl;
                cout << "2).Available yatch" << endl;
                cout << "3).Make reservation" << endl;
                cout << "Enter your option or press 4 to exit...";
                while (!(cin >> opt))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter an integer: ";
                }
                switch (opt)
                {
                case 1:
                    system("cls");
                    cout << "\n\t\t\t\t--------------------------------" << endl;
                    cout << "\t\t\t\t***Welcome to management page***" << endl;
                    cout << "\t\t\t\t--------------------------------" << endl;
                    cout << "\n\t\tEnter your username: ";
                    cin >> user;
                    cout << "\n\t\tEnter your password: ";
                    cin >> pass;
                    for (int i = 0; i < count; i++)
                    {
                        if (user == m[i].Get_username() && pass == m[i].Get_password())
                        {
                            cout << "\n\n\t\t\t\t\t\t-------------------" << endl;
                            cout << "\t\t\t\t\t\t***Add new Yatch***" << endl;
                            cout << "\t\t\t\t\t\t-------------------" << endl;
                            cout << "\n\n\t\tEnter make of yatch: ";
                            cin >> make;
                            y[yc].set_make(make);
                            cout << "\t\tEnter model of yatch: ";
                            while (!(cin >> model))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            y[yc].set_model(model);
                            cout << "\t\tEnter varient of yatch: ";
                            cin >> varient;
                            y[yc].set_varient(varient);
                            cout << "\t\tEnter per_day_rent of yatch: ";
                            while (!(cin >> per_day_rent))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            y[yc].set_pdr(per_day_rent);
                            cout << "\t\tEnter size of yatch: ";
                            while (!(cin >> size))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            y[yc].set_size(size);
                            cout << "\t\tEnter design of yatch: ";
                            cin >> design;
                            y[yc].set_design(design);
                            cout << "\t\tEnter Material of yatch: ";
                            cin >> Material;
                            y[yc].set_material(Material);
                            cout << "\t\tEnter speed of yatch: ";
                            while (!(cin >> speed))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            y[yc].set_speed(speed);
                            cout << "\t\tEnter Crew_Capacity of yatch: ";
                            while (!(cin >> Crew_Capacity))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Invalid input. Please enter an integer: ";
                            }
                            y[yc].set_crew_capacity(Crew_Capacity);
                            cout << "\t\tEnter Flag_and_Registration of yatch: ";
                            cin >> Flag_and_Registration;
                            y[yc].set_Flag_and_Registration(Flag_and_Registration);
                            y[yc].set_id(yc + 1);
                            yc++;
                        }
                    }
                    break;
                case 2:
                    system("cls");
                    cout << "\t\t\t\t\t--------------------------------" << endl;
                    cout << "\t\t\t\t\t***Details of Available yatch***" << endl;
                    cout << "\t\t\t\t\t--------------------------------" << endl;
                    do
                    {
                        for (int i = 0; i < yc; i++)
                        {
                            cout << y[i] << endl;
                        }
                        cout << "\n\tPress 'q' to exit...";
                        cin >> choice;
                    } while (choice != 'q');
                    break;
                case 3:
                    system("cls");
                    cout << "\t\t\t\t\t--------------------------------" << endl;
                    cout << "\t\t\t\t\t*********Yacht bookings*********" << endl;
                    cout << "\t\t\t\t\t--------------------------------" << endl;

                    cout << "\n\n\t\t\tEnter yatch ID: ";
                    cin >> bid;
                    cout << "Enter day you want to book: ";
                    cin >> dd;
                    cout << "Enter month you want to book: ";
                    cin >> mm;
                    cout << "Enter year you want to book: ";
                    cin >> yyyy;
                    for (int i = 0; i < yc; i++)
                    {
                        if (bid == y[i].get_id())
                        {
                            if (y[i].get_day() == dd && y[i].get_mm() == mm && y[i].get_yyyy() == yyyy)
                            {
                                do
                                {
                                    cout << "\n\t\t\tYacht is already booked for this date" << endl;
                                    cout << "\t\tPress 'q' to exit....";
                                    cin >> choice;
                                } while (choice != 'q');
                            }
                            else
                            {
                                y[i].set_date(dd, mm, yyyy);
                                y[i].set_flag(1);
                                cin >> c[cc];
                            }
                        }
                    }
                    break;
                }
            } while (opt != 4);
            break;
        case 4:
            system("cls");
            cout << "\n\t\t\t---------------------" << endl;
            cout << "\t\t\tWelcome to login page" << endl;
            cout << "\t\t\t---------------------" << endl;

            cout << "\t\tEnter your username: ";
            cin >> user;
            cout << "\n\t\tEnter your password: ";
            cin >> pass;
            for (int i = 0; i < count; i++)
            {
                if (user == m[i].Get_username() && pass == m[i].Get_password())
                {
                    do
                    {
                        system("cls");
                        cout << "\n\t\t\t---------------------" << endl;
                        cout << "\t\t\t***Cargo Shipments***" << endl;
                        cout << "\t\t\t---------------------" << endl;
                        cout << "\n\t\t1)Cargo a shipment" << endl;
                        cout << "\t\t2)Summary report" << endl;
                        cout << "\t\t3)Search a shipment" << endl;
                        cout << "\t\tPress 4 to go to main menue";
                        cin >> opt;
                        switch (opt)
                        {
                        case 1:
                            system("cls");
                            cout << "\n\t\t\t----------------------" << endl;
                            cout << "\t\t\t****Cargo Shipment****" << endl;
                            cout << "\t\t\t----------------------" << endl;
                            cin >> crg[cargo];
                            crg[cargo].set_id(cargo);
                            cargo++;
                            break;
                        case 2:
                            do
                            {
                                cout << "\n\t\t\t--------------------------------------" << endl;
                                cout << "\t\t\t****Summary report of all shipment****" << endl;
                                cout << "\t\t\t--------------------------------------" << endl;
                                for (int i = 0; i < cargo; i++)
                                {
                                    cout << crg[i];
                                }
                                cout << "\tPress 'q' to exit...";
                                cin >> choice;
                            } while (choice != 'q');
                            break;
                        case 3:
                            cout << "\n\t\t\t--------------------------------------" << endl;
                            cout << "\t\t\t     ******Search a Shipment******    " << endl;
                            cout << "\t\t\t--------------------------------------" << endl;
                            cout << "\n\t\tEnter booking Id: ";
                            cin >> bid;
                            for (int i = 0; i < cargo; i++)
                            {
                                if (bid == crg[i].get_id())
                                {
                                    do
                                    {
                                        flag = 1;
                                        cout << crg[i];
                                        cout << "\n\t\tPress 'q' to exit...";
                                        cin >> choice;
                                    } while (choice != 'q');
                                }
                                else
                                {
                                    flag = 0;
                                }
                            }
                            if (flag == 0)
                            {
                                do
                                {
                                    cout << "\n\t\tNo shipment found press 'q to exit'...";
                                    cin >> choice;
                                } while (choice != 'q');
                            }
                            break;
                        }
                    } while (opt != 4);
                }
            }
            break;
        }
    } while (opt != 5);
}

string management::Get_adusername()
{
    return adminuser;
}
void management::Set_name(string n)
{
    name = n;
}
void management::Set_gender(string n)
{
    gender = n;
}
void management::Set_age(int n)
{
    age = n;
}
void management::Set_cnic(int n)
{
    cnic = n;
}
void management::Set_username(string n)
{
    username = n;
}
void management::Set_password(string n)
{
    password = n;
}
string management::Get_name()
{
    return name;
}
string management::Get_gender()
{
    return gender;
}
int management::Get_age()
{
    return age;
}
int management::Get_cnic()
{
    return cnic;
}
string management::Get_username()
{
    return username;
}
string management::Get_password()
{
    return password;
}
void management::Creataccount()
{
    int ag, i;
    string nam, gen, user, pass;
    string adpass, aduser;
    char opt;

    system("cls");
    cout << "\t\t\t\t------------------------" << endl;
    cout << "\t\t\t\t***Create New account***" << endl;
    cout << "\t\t\t\t------------------------" << endl;
    cout << "\n\n\t\t\tEnter admin username: ";
    cin >> aduser;
    cout << "\t\t\tEnter admin password: ";
    cin >> adpass;
    if (adpass == adminpass && aduser == adminuser)
    {

        cout << "\n\t\t\t\t------------------------------------------------" << endl;
        cout << "\t\t\t\t***Welcome to new management account creation***" << endl;
        cout << "\t\t\t\t------------------------------------------------" << endl;

        cout << "\n\t\tEnter your name: ";
        cin >> nam;
        Set_name(nam);
        cout << "\t\tEnter your gender(male/female): ";
        cin >> gen;
        Set_gender(gen);
        cout << "\t\tEnter your age: ";
        while (!(cin >> ag))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        Set_age(ag);
        cout << "\t\tEnter your cnic: ";
        while (!(cin >> i))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        Set_cnic(i);
        cout << "\t\tCreate a username: ";
        cin >> user;
        Set_username(user);
        cout << "\t\tCreate password: ";
        cin >> pass;
        Set_password(pass);
        do
        {
            cout << "\n\t\t\t\t------------------------------------" << endl;
            cout << "\t\t\t\tYour account is created sucessfuilly" << endl;
            cout << "\t\t\t\t------------------------------------" << endl;
            cout << "\t\tPress 'q' to exit...";
            cin >> opt;
        } while (opt != 'q');
    }
    else
    {
        do
        {
            cout << "\n\t\tUsrename or password is wrong please enter correct password\npress 'q' to exit..." << endl;
            cin >> opt;
        } while (opt != 'q');
    }
}
void management::loginaccount(string user, string pass)
{
    char choice;
    int ag, i, opt;
    string nam, gen;

    do
    {
        system("cls");
        cout << "\n\t\t\t-----------------------" << endl;
        cout << "\t\t\tWelcome to your account" << endl;
        cout << "\t\t\t-----------------------" << endl;

        cout << "\n\t\t1).View details" << endl;
        cout << "\t\t2).Change username" << endl;
        cout << "\t\t3).Change password" << endl;
        cout << "Enter your option or press 4 to exit...";
        while (!(cin >> opt))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        switch (opt)
        {
        case 1:
            do
            {
                cout << "\n\t\t\t------------------" << endl;
                cout << "\t\t\tManagement details" << endl;
                cout << "\t\t\t------------------" << endl;
                cout << "\tName: " << name << endl;
                cout << "\tAge: " << age << endl;
                cout << "\tGender: " << gender << endl;
                cout << "\tCNIC: " << cnic << endl;
                cout << "\tUsername: " << username << endl;
                cout << "\tPassword: " << password << endl;
                cout << "\nPress 'q' to exit...";
                cin >> choice;
            } while (choice != 'q');
            break;
        case 2:
            cout << "\n\t\tEnter your current username: ";
            cin >> user;
            if (user == username)
            {
                cout << "\tEnter your new username: ";
                cin >> user;
                Set_username(user);
                do
                {
                    cout << "\n\t\t\t-------------------------------------" << endl;
                    cout << "\t\t\tusername has been updated sucessfully" << endl;
                    cout << "\t\t\t-------------------------------------" << endl;
                    cout << "\t\tPress 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
            else
            {
                do
                {
                    cout << "Invalid username!\nPress 'q' to exit...";
                    cin >> choice;

                } while (choice != 'q');
            }

            break;
        case 3:
            cout << "\n\t\tEnter your current password: ";
            cin >> pass;
            if (pass == password)
            {
                cout << "\tEnter your new password: ";
                cin >> pass;
                Set_password(pass);
                do
                {
                    cout << "\n\t\t\t-------------------------------------" << endl;
                    cout << "\t\t\tpassword has been updated sucessfully" << endl;
                    cout << "\t\t\t-------------------------------------" << endl;
                    cout << "\t\tPress 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
            else
            {
                do
                {
                    cout << "Invalid password!\nPress 'q' to exit...";
                    cin >> choice;

                } while (choice != 'q');
            }
            break;
        }
    } while (opt != 4);
}
void management::display_available_management()
{
    cout << "\n\t\t\t--------------------" << endl;
    cout << "\t\t\tName: " << name << endl;
    cout << "\t\t\tUsername: " << username << endl;
    cout << "\t\t\tGender: " << gender << endl;
    cout << "\t\t\tAge: " << age << endl;
    cout << "\t\t\tCNIC: " << cnic << endl;
    cout << "\t\t\t--------------------" << endl;
}

void ycustomer::Set_name(string n)
{
    name = n;
}
void ycustomer::Set_gender(string n)
{
    gender = n;
}
void ycustomer::Set_age(int n)
{
    age = n;
}
string ycustomer::Get_name()
{
    return name;
}
string ycustomer::Get_gender()
{
    return gender;
}
int ycustomer::Get_age()
{
    return age;
}
void ycustomer::Set_permanent_adress(string n)
{
    Permanant_adress = n;
}
void ycustomer::Set_current_location(string n)
{
    Current_location = n;
}
void ycustomer::Set_phone_number(int n)
{
    phone_number = n;
}
void ycustomer::Set_advance_payment(float n)
{
    advance_payment = n;
}
string ycustomer::get_permanent_adress()
{
    return Permanant_adress;
}
string ycustomer::get_current_location()
{
    return Current_location;
}
int ycustomer::get_phone_number()
{
    return phone_number;
}
float ycustomer::get_advance_payment()
{
    return advance_payment;
}

void yatch::set_make(string n)
{
    make = n;
}
void yatch::set_model(int n)
{
    model = n;
}
void yatch::set_varient(string n)
{
    varient = n;
}
string yatch::get_make()
{
    return make;
}
int yatch::get_model()
{
    return model;
}
string yatch::get_varient()
{
    return varient;
}
void yatch::set_size(int n)
{
    size = n;
}
void yatch::set_design(string n)
{
    design = n;
}
void yatch::set_material(string n)
{
    Material = n;
}
void yatch::set_speed(int n)
{
    speed = n;
}
void yatch::set_crew_capacity(int n)
{
    Crew_Capacity = n;
}
void yatch::set_pdr(float n)
{
    per_day_rent = n;
}
void yatch::set_Flag_and_Registration(string n)
{
    Flag_and_Registration = n;
}
void yatch::set_id(int n)
{
    id = n;
}
int yatch::get_id()
{
    return id;
}
void yatch::set_flag(int n)
{
    flag = n;
}
int yatch::get_flag()
{
    return flag;
}
void yatch::set_date(int n, int m, int p)
{
    dd = n;
    mm = m;
    yyyy = p;
}
int yatch::get_day()
{
    return dd;
}
int yatch::get_mm()
{
    return mm;
}
int yatch::get_yyyy()
{
    return yyyy;
}

void Itravels::set_country(string c)
{
    country = c;
}
void Itravels::set_firstclass_price(float n)
{
    firstclass_price = n;
}
void Itravels::set_bussisness_price(float n)
{
    bussisness_price = n;
}
void Itravels::set_economy_price(float n)
{
    economy_price = n;
}
void Itravels::set_dep_date(int d, int m, int y)
{
    dep_dd = d;
    dep_mm = m;
    dpe_yyyy = y;
}
void Itravels::set_arv_date(int d, int m, int y)
{
    arv_dd = d;
    arv_mm = m;
    arv_yyyy = y;
}

void Ibookings::set_payment()

{
    char choice;
    cout << "\n\t\t\t------------------------------------------" << endl;
    cout << "\t\t\t**************Payment process**************" << endl;
    cout << "\t\t\t-------------------------------------------" << endl;
    cout << "\t\tEnter your Debit card Number: ";
    cin >> cardnumber;
    if ((cardnumber >= 1000000000000000LL && cardnumber <= 9999999999999999LL))
    {
        cout << "\t\tEnter card expiry date year: ";
        while (!(cin >> expdate))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        if (expdate >= 2024 || expdate <= 2028)
        {
            cout << "\t\tEnter your 3 digit cvc number: ";
            while (!(cin >> cvc))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter an integer: ";
            }
            if (cvc >= 100 && cvc <= 999)
            {
                flag = 1;
                do
                {
                    cout << "Your payment is processed... Press 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
            else
            {
                do
                {
                    cout << "Invalid cvc number... Press 'q' to exit..." << endl;
                    cin >> choice;
                } while (choice != 'q');
            }
        }
        do
        {
            cout << "Invalid expiry date... Press 'q' to exit..." << endl;
            cin >> choice;
        } while (choice != 'q');
    }
    else
    {
        do
        {
            cout << "Invalid card number... Press 'q' to exit..." << endl;
            cin >> choice;
        } while (choice != 'q');
    }
}

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void crono(){
    vector<string> dia_semana;
    vector<string> mes;
    time_t now = time(0);
    tm * time = localtime(&now);	
	
	//Dia de semana
	dia_semana.push_back("Domingo");
	dia_semana.push_back("Lunes");
	dia_semana.push_back("Martes");
	dia_semana.push_back("Miercoles");
	dia_semana.push_back("Jueves");
	dia_semana.push_back("Viernes");
	dia_semana.push_back("Sabado");
	
    //Mes
	mes.push_back("Enero");
	mes.push_back("Febero");
	mes.push_back("Marzo");
	mes.push_back("Abril");
	mes.push_back("Mayo");
	mes.push_back("Junio");
	mes.push_back("Julio");
	mes.push_back("Agosto");
    mes.push_back("Septiembre");
	mes.push_back("Octubre");
	mes.push_back("Noviembre");
	mes.push_back("Diciembre");
			
	
	int year = 1900 + time->tm_year;		
	cout<<"\t\t\t\t\t\t\t\t\t "<< dia_semana[time->tm_wday] << ", ";
	cout<<time->tm_mday << " de " << mes[time->tm_mon] << " del " << year << endl;
	cout<<"\t\t\t\t\t\t\t\t\t "<< time->tm_hour << " : " << time->tm_min << " : " <<time->tm_sec<<endl;
}

class loginpage{
private:
    string user = "123", pass = "321";
    string username, password, email, new_pass1, new_pass2;
    int logintime=1;
    char activo, inactivo;
    bool status;
    void login_time(){
        while ( logintime <= 1){
            system("cls");
            cout << "Por ser primera vez debe cambiar la contrasena"<<endl;
            cout << "Ingresar nueva contrasena: "; cin>>new_pass1;
            cout << "Ingresar nueva contrasena: "; cin>>new_pass2;
            system("cls");
            cout << "Contrasena cambiada" <<endl;
            cout << "Favor de volver a entrar"<<endl;
            system("pause");
            login();
        if (new_pass1==new_pass2){
            pass = new_pass2;
            logintime++;
        }else 
            cout << "Ambas contrasenas deben ser iguales" <<endl;
        }
    }
public:
    loginpage(){
        activo = true;
        inactivo = false;
        status = activo;
    }
    void login(){
        system("cls");
        cout << "Username: "; cin >> username;
        cout << "\nPassword: "; cin >> password;
        if (username == user && password == pass && status == activo){
            crono();
            login_time();
            cout << "Bienvenido"<<endl;

        }if (username == user && password == pass && status == inactivo){
            cout << "Cuenta inactiva favor de contactar con un admin para activarla."<<endl;

        }if (username != user && password != pass && status == activo){
            cout << "username o contrasena incorrecta."<<endl;
            login();
        }
    }
    void pass_change(){
        cout << "Ingresar nueva contrasena: "; cin>>new_pass1;
        cout << "Ingresar nueva contrasena: "; cin>>new_pass2;
        if (new_pass1==new_pass2){
            pass = new_pass2;
            cout << "Contrasena cambiada" <<endl;
            cout << "Favor de volver a entrar"<<endl;
            system("pause");
            login();
        }else if(new_pass1!=new_pass2){
            cout << "Ambas contrasenas deben ser iguales" <<endl;
        }
    }
};

class tickets{
    private:
    string nom, apell, id, email,mess;
    char carrera, cat;
    int omenu, oticket, count_ticket=0;

    public:
    void ticketnum();
    void new_ticket();
    void vertickets();
};

void tickets::ticketnum(){
    srand (time(0));
    for (int i = 0; i < 4; i++){
         cout << rand();
        }
};

void tickets::new_ticket(){
    cout << "\nBienvenido al systema de ticket de la Universidad."<<endl;
    cout << "\nFavor de llenar los requisitos para su ticket."<<endl;
    cout << "\nNombre: "; cin>>nom;
    cout << "\nApellido: "; cin>>apell;cin.ignore(); 
    cout << "\nIdentificacion "; cin>>id;
    cout << "\nCorreo electronico: "; cin>>email;
    cout << "\nCarrera que estudia: "; cin>>carrera;
    cout << "\nCategoria de ticket: "; cin>>cat;cin.ignore();
    cout << "\nMensaje: "<<endl; getline(cin,mess);
    cout << "\n\nNumero de ticket: "<<"#"; ticketnum();
};

void tickets::vertickets(){
    if (count_ticket==0){
        cout << "No existe tickets"<<endl;
    }else if (count_ticket>0){
        cout << count_ticket << ". " << rand(); cin >> oticket;
    }
};

class menupage : public loginpage, public tickets{
    private:
    int omenu, count_ticket=0, opciones;

    public:
    void menu();
};

void menupage::menu(){
    system("cls");
    cout << "Menu: \n1. Subir un ticket. \n2. Ver tickets. \n3. Cambiar contrasena \n4. Salir"<<endl;
    cin >> omenu;
    switch (omenu){
    case 1:
        system("cls");
        new_ticket();
        cout << "\nEnviar? \n1. Si \n2. No"<<endl; cin >> opciones;
        if (opciones==1){
            count_ticket++;
            menu();
        }else
            menu();
        break;
    
    case 2:
        vertickets();
        system("pause");
        menu();
        break;

    case 3:
        pass_change();
        system("pause");
        break;
    
    case 4:
        system("cls");
        cout << "4"<<endl;
        break;
    
    default:
        cout << "Opcion invalida favor de volver a intentarlo."<<endl;
        menu();
    }
};

int main(){
    int omenu, count_ticket=0, opciones;
    string password;
    menupage loginweb;

    loginweb.login();
    system("pause");
    loginweb.menu();

    return 0;
}
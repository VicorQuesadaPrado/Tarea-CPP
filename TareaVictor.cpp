#include <iostream>
using namespace std;
class Students
{
private:
    string studentName;
public:
    void setStudentName(string name) {
        studentName = name;
    }
    string getStudentName() {
        return studentName;
    }
    Students() {
        setStudentName("");
    };
    Students(string name) {

    };
    void printStudents() {
        cout << getStudentName();
    }
};
//-----------------------------------------------------------------
class Subjects
{
private:
    string subjectName;
public:
    void setSubjectName(string subject) {
        subjectName = subject;
    }
    string getSubjectName() {
        return subjectName;
    }
    Subjects() {
        setSubjectName("");
    };
    Subjects(string nameM_) {

    };
    void printSubjects() {
        cout << getSubjectName();
    }
};
//-----------------------------------------------------------------
void fillStudentsVector(Students studentsVector[], int x) {
    string name;
    for (int index = 0; index < x; index++) {
        cout << "digite el nombre del estudiante # " << index << endl;
        cin >> name;
        studentsVector[index].setStudentName(name);
    }
};
//-----------------------------------------------------------------
void fillSubjectsVector(Subjects subjectsVector[], int x) {
    string subject;
    for (int index = 0; index < x; index++) {
        cout << "digite el nombre de la materia # " << index << endl;
        cin >> subject;
        subjectsVector[index].setSubjectName(subject);
    }
};
//-----------------------------------------------------------------
void fillMatrix(int gradesMatrix[100][100], Students studentsVector[], Subjects subjectsVector[], int subjects, int students) {
    for (int index = 0; index < subjects; index++) {
        for (int index2 = 0; index2 < subjects; index2++) {
            if (gradesMatrix[index][index2] == NULL) {
                int grade;
                cout << "Digite la nota de la materia " << subjectsVector[index].getSubjectName() << " del estudiante " << studentsVector[index2].getStudentName() << endl;
                cin >> grade;
                gradesMatrix[index][index2] = grade;
            }
        }
    }
};
//-----------------------------------------------------------------
void start(int gradesMatrix[100][100], int estudiantes, int materias) {
    for (int index = 0; index < materias; index++) {
        for (int index2 = 0; index2 < estudiantes; index2++) {
            gradesMatrix[index][index2] = NULL;
        }
    }
}
//-----------------------------------------------------------------
void print(Students studentsVector[], Subjects subjectsVector[], int gradesMatrix[100][100], int subjects, int students) {
    cout << "______________________________________" << endl;
    for (int index = 0; index < subjects; index++) {
        if (index == 0) {
            cout << "         " << "Students        ";
        }
        for (int index2 = 0; index2 < students; index2++) {
            if (index == 0) {

                studentsVector[index2].printStudents();
            }
            else if (index != 0 && index2 != 0) {
                cout << "  " << gradesMatrix[index - 1][index2 - 1];
            }
        }
        cout << endl;
        if (index == 0) {
            cout << "Subjects Grades    ";
            subjectsVector[index].printSubjects();
        }
        else if (index != 0) {
            cout << "                   ";
            subjectsVector[index].printSubjects();
        }
        cout << endl;
        cout << "______________________________________" << endl;
    }
};
//-----------------------------------------------------------------
string status(int grade) {
    if (grade < 50) {
        return "Reprobado";
    }
    else  if (grade <= 69 && grade > 50) {
        return "Parcial";
    }
    else  if (grade >= 70) {
        return "Aprobado";
    }
    else  if (grade == 0 || grade == NULL) {
        return "Nota no definida ";
    }
}
//-----------------------------------------------------------------
void studentsStatus(int opc, Students studentsVector[], int gradesMatrix[100][100], int subjects, int students) {
    string clave;
    int cont = 0;
    if (opc == 1) {
        clave = "Reprobado";
    }
    else if (opc == 2) {
        clave = "Parcial";
    }
    else if (opc == 3) {
        clave = "Aprobado";
    }
    else if (opc == 4) {
        clave = "Nota no definida ";
    }
    for (int index = 0; index < students; index++) {
        for (int index2 = 0; index2 < subjects; index2++) {
            if (status(gradesMatrix[index2][index]) == clave) {
                cont++;
            }
            else {
                index2 = 0;
                index++;
            }
            if (cont == subjects) {
                studentsVector[index].printStudents();
                cout << endl;
            }

        }
    }
}
//-----------------------------------------------------------------

void subjectsStatus(int subject, int gradesMatrix[100][100], int students) {
    int cont = 0;
    int average = 0;
    int max = gradesMatrix[subject][0];
    int min = gradesMatrix[subject][0];

    for (int index = 0; index < students; index++) {
        if (gradesMatrix[subject][index] == NULL || gradesMatrix[subject][index] == 0) {
            average = average + 0;
        }
        else if (gradesMatrix[subject][index] != 0) {
            if (max < gradesMatrix[subject][index]) {
                max = gradesMatrix[subject][index];
                average = average + gradesMatrix[subject][index];
            }
            else if (min > gradesMatrix[subject][index]) {
                min = gradesMatrix[subject][index];
                average = average + gradesMatrix[subject][index];
            }


            cont++;
        }
    }
    cout << "La nota maxima nota es= " << max << endl;
    cout << "La nota minima es= " << min << endl;
    cout << "El promedio es= " << average / cont << endl;
    cout << "Cantidad total de estudiantes que poseen una nota= " << cont << endl;

}


//-----------------------------------------------------------------
void reporte(int student, int subjects, int students, int gradesMatrix[100][100], Students studentsVector[], Subjects subjectsVector[]) {
    system("cls");
    int opc;
    cout << "______________________________________" << endl;
    cout << "Reporte de estudiantes" << endl;
    cout << endl;
    cout << "Listado de todas las notas y estudiantes" << endl;
    print(studentsVector, subjectsVector, gradesMatrix, subjects, students);
    cout << "______________________________________" << endl;
    cout << "Notas del estudiante: " << studentsVector[student].getStudentName() << endl;
    for (int index = 0; index < subjects; index++) {
        subjectsVector[index].printSubjects();
        cout << endl;
        cout << gradesMatrix[index][student] << endl;
        cout << status(gradesMatrix[index][student]);
        cout << endl;
    }
    cout << "______________________________________" << endl;
    cout << "Estudiantes en un estado especifico en todas las materias" << endl;
    cout << "Digite 1 si quiere saber los que reprobaron" << endl;
    cout << "Digite 2 si quiere saber los que pueden ir al parcial" << endl;
    cout << "Digite 3 si quiere saber los que aprobaron" << endl;
    cout << "Digite 4 si quiere saber los que no tienen nota definida" << endl;
    cin >> opc;
    cout << "______________________________________" << endl;
    cout << "Listado de estudiantes que cumplen con lo buscado:" << endl;
    studentsStatus(opc, studentsVector, gradesMatrix, subjects, students);
    cout << "______________________________________" << endl;
    cout << "Resumen de las materias" << endl;
    cout << endl;
    for (int index = 0; index < subjects; index++) {
        cout << subjectsVector[index].getSubjectName() << ": " << endl;
        subjectsStatus(index, gradesMatrix, students);
        cout << endl;
        cout << "______________________________________" << endl;
    }




}

//-----------------------------------------------------------------
int main()

{
    int option;
    int static subjects;
    int static students;
    int  matrix[100][100];


    cout << "Bienvenido al sistema" << endl;
    cout << "______________________________________" << endl;
    cout << "Digite 1 si quiere empezar de 0" << endl;
    cout << "Digite 2 si quiere iniciar con datos" << endl;
    cout << "Digite 0 si quiere salir del programa" << endl;
    cout << "______________________________________" << endl;
    cin >> option;
    system("cls");
    cout << "Digite la cantidad de estudiantes " << endl;
    cin >> students;
    cout << "Digite la cantidad de materias" << endl;
    cin >> subjects;
    start(matrix, students, subjects);
    Students studentsVector[100];
    Subjects subjectsVector[100];
    if (option == 1) {
        int opc;
        system("cls");
        fillStudentsVector(studentsVector, students);
        fillSubjectsVector(subjectsVector, subjects);
        fillMatrix(matrix, studentsVector, subjectsVector, subjects, students);

        print(studentsVector, subjectsVector, matrix, subjects, students);
        cout << "Digite el numero de estudiante que quiera revisar las notas" << endl;
        cin >> opc;
        reporte(opc, subjects, students, matrix, studentsVector, subjectsVector);


    }

    else if (option == 2) {
        system("cls");

    }
    else if (option == 0) {
        system("cls");
    }
    else {
        system("cls");
        cout << "Digito una opcion invalida, ejecucion terminada" << endl;
    }
}
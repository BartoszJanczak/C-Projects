#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100 // maksymalna liczba kontaktów, jakie mo¿na przechowywaæ

struct Contact {
    char first_name[50];
    char last_name[50];
    char phone_number[20];
};

struct Contact contact_list[MAX_CONTACTS]; // tablica przechowuj¹ca kontakty
int num_contacts = 0; // liczba kontaktów przechowywanych w tablicy

void display_menu();
void add_contact();
void display_contacts();
void edit_contact();
void delete_contact();

// Funkcja g³ówna programu
int main()
{
    int option;
    do {
        display_menu();
        scanf("%d", &option);
        switch (option) {
        case 1:
            add_contact();
            break;
        case 2:
            display_contacts();
            break;
        case 3:
            edit_contact();
            break;
        case 4:
            delete_contact();
            break;
        case 5:
            printf("Do widzenia!\n");
            break;
        default:
            printf("Nieprawidlowa opcja.\n");
            break;
        }
    } while (option != 5);
    return 0;
}
// Funkcja do wyœwietlania menu programu
void display_menu() {
    printf("---------------------------------\n");
    printf("1. Dodaj kontakt\n");
    printf("2. Wyswietl liste kontaktow\n");
    printf("3. Edytuj kontakt\n");
    printf("4. Usun kontakt\n");
    printf("5. Wyjdz z programu\n");
    printf("---------------------------------\n");
    printf("Wybierz opcje (1-5): ");
}

// Funkcja do dodawania kontaktu do listy
void add_contact() {
    struct Contact new_contact;
    printf("Podaj imie: ");
    scanf("%s", new_contact.first_name);
    printf("Podaj nazwisko: ");
    scanf("%s", new_contact.last_name);
    printf("Podaj numer telefonu: ");
    scanf("%s", new_contact.phone_number);
    contact_list[num_contacts] = new_contact;
    num_contacts++;
    printf("Kontakt zostal dodany do listy.\n");
}

// Funkcja do wyœwietlania listy kontaktów
void display_contacts() {
    printf("Lista kontaktow:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s %s, %s\n", i + 1, contact_list[i].first_name, contact_list[i].last_name, contact_list[i].phone_number);
    }
}

// Funkcja do edycji kontaktu na liœcie
void edit_contact() {
    int contact_index;
    printf("Podaj numer kontaktu, ktory chcesz edytowac: ");
    scanf("%d", &contact_index);
    if (contact_index < 1 || contact_index > num_contacts) {
        printf("Nieprawidlowy numer kontaktu.\n");
        return;
    }
    struct Contact* contact = &contact_list[contact_index - 1];
    printf("Edycja kontaktu:\n");
    printf("Imie (%s): ", contact->first_name);
    scanf("%s", contact->first_name);
    printf("Nazwisko (%s): ", contact->last_name);
    scanf("%s", contact->last_name);
    printf("Numer telefonu (%s): ", contact->phone_number);
    scanf("%s", contact->phone_number);
    printf("Kontakt zostal zaktualizowany.\n");
}

// Funkcja do usuwania kontaktu z listy
void delete_contact() {
    int contact_index;
    printf("Podaj numer kontaktu, ktory chcesz usunac: ");
    scanf("%d", &contact_index);
    if (contact_index < 1 || contact_index > num_contacts) {
        printf("Nieprawidlowy numer kontaktu.\n");
        return;
    }
    for (int i = contact_index - 1; i < num_contacts - 1; i++) {
        contact_list[i] = contact_list[i + 1];
    }
    num_contacts--;
    printf("Kontakt zostal usuniety z listy.\n");
}


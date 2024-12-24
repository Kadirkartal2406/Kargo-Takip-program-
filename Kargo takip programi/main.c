#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Şehir düğümü
typedef struct CityNode {
    int city_id;                // Şehir ID'si
    char city_name[50];         // Şehir adı
    float time;                 // Yol süresi (saat cinsinden)
    struct CityNode *child;     // İlk alt şehir (çocuk düğüm)
    struct CityNode *sibling;   // Aynı seviyedeki sonraki şehir (kardeş düğüm)
} CityNode;

// Yeni bir şehir düğümü oluşturma
CityNode* create_city(int city_id, const char *city_name, float time) {
    CityNode *new_city = (CityNode *)malloc(sizeof(CityNode));
    new_city->city_id = city_id;
    strcpy(new_city->city_name, city_name);
    new_city->time = time;
    new_city->child = NULL;
    new_city->sibling = NULL;
    return new_city;
}

// Alt şehir ekleme
void add_city(CityNode *parent, int city_id, const char *city_name, float time) {
    CityNode *new_city = create_city(city_id, city_name, time);
    if (parent->child == NULL) {
        parent->child = new_city; // İlk çocuk
    } else {
        CityNode *temp = parent->child;
        while (temp->sibling != NULL) {
            temp = temp->sibling; // Son kardeşe git
        }
        temp->sibling = new_city; // Yeni kardeşi ekle
    }
}
// Alt şehirleri eklemek için bir fonksiyon
void add_cities(CityNode *parent) {
    if (parent == NULL) return;

    // Şehir isimleri ve zamanları
    if (parent->city_id == 1) {  // "Merkez" şehri için
        add_city(parent, 2, "A", 1.5);
        add_city(parent, 3, "B", 2.0);
        add_city(parent, 4, "C", 2.5);
    }

    // A şehrinin alt şehirleri
    CityNode *A = parent->child;
    if (A != NULL) {
        add_city(A, 5, "D", 1.0);
        add_city(A, 6, "E", 2.0);
    }

    // B şehrinin alt şehirleri
    CityNode *B = A->sibling;
    if (B != NULL) {
        add_city(B, 7, "F", 0.5);
        add_city(B, 8, "G", 1.8);
    }

    // C şehrinin alt şehirleri
    CityNode *C = B->sibling;
    if (C != NULL) {
        add_city(C, 9, "H", 1.2);
        add_city(C, 10, "I", 2.0);
    }

    // D şehrinin alt şehirleri
    CityNode *D = A->child;
    if (D != NULL) {
        add_city(D, 11, "J", 2.3);
        add_city(D, 12, "K", 1.7);
    }

    // E şehrinin alt şehirleri
    CityNode *E = D->sibling;
    if (E != NULL) {
        add_city(E, 13, "L", 2.5);
        add_city(E, 14, "M", 1.6);
    }

    // F şehrinin alt şehirleri
    CityNode *F = B->child;
    if (F != NULL) {
        add_city(F, 15, "N", 1.4);
        add_city(F, 16, "O", 3.1);
    }

    // G şehrinin alt şehirleri
    CityNode *G = F->sibling;
    if (G != NULL) {
        add_city(G, 17, "P", 1.9);
        add_city(G, 18, "Q", 0.9);
    }

    // H şehrinin alt şehirleri
    CityNode *H = C->child;
    if (H != NULL) {
        add_city(H, 19, "R", 2.2);
        add_city(H, 20, "S", 3.0);
    }
}

// Ağacı konsolda görselleştirme
void display_tree(CityNode *root, int depth) {
    if (root == NULL) return;

    // Derinliğe göre girinti ekle
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("|-- %s (ID: %d, Time: %.2f hours)\n", root->city_name, root->city_id, root->time);

    // Çocukları yazdır
    display_tree(root->child, depth + 1);

    // Kardeşleri yazdır
    display_tree(root->sibling, depth);
}
// Kullanıcıdan şehir ismi alarak ilgili şehir bulma ve mesafe hesaplama
float calculate_travel_time(CityNode *root, const char *city_name) {
    if (root == NULL) return -1;  // Şehir bulunamadı

    // Eğer şehir bulunduysa, zamanını döndür
    if (strcmp(root->city_name, city_name) == 0) {
        return root->time;
    }

    // Çocukları kontrol et
    float time = calculate_travel_time(root->child, city_name);
    if (time != -1) {
        return time + root->time;  // Çocukla bağlantılı mesafeyi ekle
    }

    // Kardeşleri kontrol et
    return calculate_travel_time(root->sibling, city_name);
}

// Belleği temizleme
void free_tree(CityNode *root) {
    if (root == NULL) return;
    free_tree(root->child);
    free_tree(root->sibling);
    free(root);
}

// Gönderi bilgileri
typedef struct Shipment {
    int shipment_id;
    char tracking_number[10];   // Takip numarası
    char date[11]; // "YYYY-MM-DD"
    int durum; // "Delivered" veya "Not Delivered"
    float delivery_time; // Teslim süresi (gün)
    char delivery_adress[10]; // Teslimat adresi
    struct Shipment *next;
} Shipment;

// Müşteri bilgileri
typedef struct Customer {
    int customer_id; // Benzersiz müşteri ID
    char name[50];   // İsim ve Soyisim
    Shipment *shipment_history; // Gönderim geçmişi (Linked List)
    struct Customer *next;      // Sonraki müşteri
} Customer;

void prefill_customers(Customer **customer_list, CityNode *root) {
    // Örnek Müşteriler
    add_customer(customer_list, 1, "Kadir Kartal");
    add_customer(customer_list, 2, "Melih Turgut");
    add_customer(customer_list, 3, "Salih Karabulak");




    char tracking_number1[20];
    generate_tracking_number(tracking_number1);  // Rastgele takip numarası

    add_shipment(&((*customer_list)->shipment_history), 101, tracking_number1, "2024-09-11", 1 ,2, "K");

    char tracking_number2[20];
    generate_tracking_number(tracking_number2);
    add_shipment(&((*customer_list)->shipment_history), 102, tracking_number2, "2024-09-23", 2, 2,"N");


    char tracking_number3[20];
    generate_tracking_number(tracking_number3);
    add_shipment(&(((*customer_list)->next)->shipment_history), 201, tracking_number3, "2024-12-02", 1,  2, "M");

    char tracking_number4[20];
    generate_tracking_number(tracking_number4);
    add_shipment(&(((*customer_list)->next)->shipment_history), 202, tracking_number4, "2024-12-04", 2, 2, "E");

    char tracking_number5[20];
    generate_tracking_number(tracking_number5);
    add_shipment(&((((*customer_list)->next)->next)->shipment_history), 301, tracking_number5, "2024-12-02", 1,2 , "S");

    char tracking_number6[20];
    generate_tracking_number(tracking_number6);
    add_shipment(&((((*customer_list)->next)->next)->shipment_history), 302, tracking_number6, "2024-12-04", 2, 2, "A");

}

void add_customer(Customer **head, int customer_id, const char *name) {
    Customer *new_customer = (Customer *)malloc(sizeof(Customer));
    new_customer->customer_id = customer_id;
    strcpy(new_customer->name, name);
    new_customer->shipment_history = NULL;
    new_customer->next = NULL;

    if (*head == NULL) {
        *head = new_customer; // Liste boşsa, ilk müşteri
    } else {
        Customer *temp = *head;
        while (temp->next) {
            temp = temp->next; // Listenin sonuna git
        }
        temp->next = new_customer;
    }
}
// Rastgele 9 haneli takip numarası oluşturma (hem harfler hem de sayılar içerir)
void generate_tracking_number(char *tracking_number) {
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  // Harfler ve sayılar
    for (int i = 0; i < 9; i++) {
        int random_index = rand() % (sizeof(characters) - 1);  // Rastgele karakter seç
        tracking_number[i] = characters[random_index];          // Seçilen karakteri takip numarasına ekle
    }
    tracking_number[9] = '\0';
}




void add_shipment(Shipment **head, int shipment_id,const char *tracking_number, const char *date,  int durum, float delivery_time,const char *delivery_adress) {
    Shipment *new_shipment = (Shipment *)malloc(sizeof(Shipment));
    new_shipment->shipment_id = shipment_id;
    strcpy(new_shipment->tracking_number, tracking_number);
    strcpy(new_shipment->date, date);
    strcpy(new_shipment->delivery_adress, delivery_adress);
    new_shipment->durum = durum;
    new_shipment->delivery_time = delivery_time;
    new_shipment->next = NULL;

    if (*head == NULL || strcmp(date, (*head)->date) < 0) {
        // Başa ekleme (tarih sırasına göre)
        new_shipment->next = *head;
        *head = new_shipment;
    } else {
        Shipment *temp = *head;
        while (temp->next && strcmp(temp->next->date, date) < 0) {
            temp = temp->next; // Doğru konuma git
        }
        new_shipment->next = temp->next;
        temp->next = new_shipment;
    }
}

void display_shipment_history(Shipment *head) {
    if (head == NULL) {
        printf("Gonderim gecmisi bos.\n");
        return;
    }
    printf("Gonderim Gecmisi:\n");
    int counter = 1;  // Kargo numarasını takip etmek için bir sayaç
    while (head) {
        printf("Kargo %d:\n", counter);  // Kargo numarasını yazdır
        printf("ID: %d\nTakip Numarasi: %s\nTarih: %s\nIl: %s\nDurum: %s\nSure: %.2f saat\n\n",
        head->shipment_id,head->tracking_number, head->date,head->delivery_adress,
        head->durum == 1 ? "Teslim Edildi" : "Teslim Edilmedi",
        head->delivery_time);

        head = head->next;
        counter++;
    }
}

void display_customer(Customer *head, int customer_id) {
    while (head) {
        if (head->customer_id == customer_id) {
            printf("Musteri: %s (ID: %d)\n", head->name, head->customer_id);
            display_shipment_history(head->shipment_history);
            return;
        }
        head = head->next;
    }
    printf("Musteri bulunamadi.\n");
}

void musteri_bilgileri(Customer **customer_list) {
    int id;
    char name[50];

    printf("Lutfen ID giriniz: ");
    scanf("%d", &id);
    // Aynı ID'ye sahip bir müşteri var mı diye kontrol et
    Customer *temp = *customer_list;
    while (temp != NULL) {
        if (temp->customer_id == id) {
            printf("Hata: Bu ID'ye sahip bir musteri zaten mevcut.\n");
            return;
        }
        temp = temp->next;
    }


    printf("Lutfen Ad ve Soyad giriniz: ");
    scanf(" %[^\n]", name);
    printf("Islem basarili\n");

    // Müşteri ekleme
    add_customer(customer_list, id, name);

}
int is_valid_address(CityNode *root, const char *delivery_address) {
    if (root == NULL) return 0;

    if (strcmp(root->city_name, delivery_address) == 0) {
        return 1;
    }

    // Çocukları kontrol et
    if (is_valid_address(root->child, delivery_address)) {
        return 1;
    }

    // Kardeşleri kontrol et
    return is_valid_address(root->sibling, delivery_address);
}

void gonderim_ekle(Customer *customer_list,CityNode *root) {
    int customer_id;
    int shipment_id;
    char date[11];
    int durum;
    char delivery_adress[10];
    float delivery_time;

    // Hangi müşteriye gönderim eklenecek?
    printf("Lutfen musteri ID'sini giriniz: ");
    scanf("%d", &customer_id);

    // Müşteriyi bul
    Customer *current = customer_list;
    while (current && current->customer_id != customer_id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Musteri bulunamadi. Gonderim eklenemedi.\n");
        return;
    }

    // Gönderim bilgilerini al
    printf("Lutfen gonderi ID'sini giriniz: ");
    scanf("%d", &shipment_id);
    printf("Lutfen gonderi tarihini giriniz (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Lutfen gonderi durumunu giriniz (1:Teslim edildi / 2:Teslim edilmedi): ");
    scanf("%d", &durum);
    printf("Lutfen teslimat adresini giriniz (A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S): ");
    scanf("%s", &delivery_adress);
    while (!is_valid_address(root, delivery_adress)) {
    printf("Hata: Girdiginiz adres gecersiz. Lutfen gecerli bir teslimat adresi giriniz: ");
    scanf("%s", delivery_adress);
}
     delivery_time = calculate_travel_time(root, delivery_adress);

      // Takip numarasını oluştur
    char tracking_number[20];
    generate_tracking_number(tracking_number);
    // Gönderimi ekle
    add_shipment(&current->shipment_history, shipment_id,tracking_number, date, durum,delivery_time, delivery_adress);

     strcpy(current->shipment_history->tracking_number, tracking_number);  // Takip numarasını ekle
    printf("Gonderim basariyla eklendi. Takip numaraniz: %s\n", tracking_number);



}


void musteri_goruntuleme(Customer *customer_list) {
    int id;
    printf("Lutfen goruntulemek istediginiz musteri ID'sini giriniz: ");
    scanf("%d", &id);

    display_customer(customer_list, id);
}
void free_customers(Customer *head) {
    while (head) {
        Shipment *shipment = head->shipment_history;
        while (shipment) {
            Shipment *next_shipment = shipment->next;
            free(shipment);
            shipment = next_shipment;
        }
        Customer *next_customer = head->next;
        free(head);
        head = next_customer;
    }
}

void display_all_customers(Customer *head) {
    if (head == NULL) {
        printf("Musteri listesi bos.\n");
        return;
    }
    printf("Tum Musteriler:\n");
    Customer *temp = head;
    while (temp) {
        printf("Musteri: %s (ID: %d)\n", temp->name, temp->customer_id);
        temp = temp->next;
    }
     // Müşteri ID'si ile seçilen müşterinin gönderim geçmişini görüntüleme
    int selected_customer_id;
    printf("Gonderim gecmisini gormek istediginiz musterinin ID'sini giriniz: ");
    scanf("%d", &selected_customer_id);

    Customer *current = head;
    while (current) {
        if (current->customer_id == selected_customer_id) {
            printf("\nSecilen Musteri: %s (ID: %d)\n", current->name, current->customer_id);
            display_shipment_history(current->shipment_history);
            return;
        }
        current = current->next;
    }

    printf("Musteri bulunamadi.\n");
}
void display_all_shipments(Customer *customer_list) {
    if (customer_list == NULL) {
        printf("Kargo listesi bos.\n");
        return;
    }

    printf("Tum Kargolar:\n");
    Customer *current_customer = customer_list;
    while (current_customer) {
        Shipment *current_shipment = current_customer->shipment_history;
        while (current_shipment) {
            printf("Musteri: %s (ID: %d)\n", current_customer->name, current_customer->customer_id);
            printf("Kargo ID: %d\n", current_shipment->shipment_id);
            printf("Takip Numarasi: %s\n", current_shipment->tracking_number);
            printf("Tarih: %s\n", current_shipment->date);
            printf("Durum: %s\n", current_shipment->durum == 1 ? "Teslim Edildi" : "Teslim Edilmedi");
            printf("Teslimat Adresi: %s\n", current_shipment->delivery_adress);
            printf("Teslim Sure: %.2f saat\n\n", current_shipment->delivery_time);

            current_shipment = current_shipment->next;
        }
        current_customer = current_customer->next;
    }
}


void kargo_sorgulama(Customer *customer_list) {

    char tracking_number[10];  // 9 karakter + null karakter
    printf("Lutfen kargo takip numarasini giriniz: ");
    scanf("%9s", tracking_number);  // 9 karakter al, null karakteri için 1 eklenmiş

    Customer *current = customer_list;
    while (current) {
        Shipment *shipment = current->shipment_history;
        while (shipment) {
            if (strcmp(shipment->tracking_number, tracking_number) == 0) {
                printf("Kargo Takip Numarasi: %s\n", shipment->tracking_number);
                printf("Gonderi ID: %d\n", shipment->shipment_id);
                printf("Tarih: %s\n", shipment->date);
                printf("Durum: %s\n", shipment->durum == 1 ? "Teslim Edildi" : "Teslim Edilmedi");
                printf("Teslimat Adresi: %s\n", shipment->delivery_adress);
                printf("Teslim Sure: %.2f saat\n", shipment->delivery_time);
                return;
            }
            shipment = shipment->next;
        }
        current = current->next;
    }
    printf("Takip numarasi bulunamadi.\n");
}


void personel_menu(Customer **customer_list, CityNode *root) {

    int giris;
    do {
        printf("\nPersonel Menusu:\n");
        printf("1 - Musteri ekleme\n");
        printf("2 - Musteri goruntuleme\n");
        printf("3 - Musteriye gonderim ekleme\n");
        printf("4 - Tum musterileri goruntuleme\n");
        printf("5 - Tum kargolari goruntuleme\n");
        printf("6 - Kargo rotalama agacini goruntule\n");
        printf("0 - Ana Menuye Don\n");
        printf("Secim: ");
        scanf("%d", &giris);

        switch (giris) {
            case 1:
                musteri_bilgileri(customer_list);
                break;
            case 2:
                musteri_goruntuleme(*customer_list);
                break;
            case 3:
                gonderim_ekle(*customer_list, root);
                break;
            case 4:
                display_all_customers(*customer_list);
                break;
            case 5:
                display_all_shipments(*customer_list);
            case 6:
                printf("Kargo Rotalama Agaci:\n");
                display_tree(root, 0);
            case 0:
                 printf("Ana Menuye donuluyor...\n");
                break;
            default:
                printf("Hatali secim. Lutfen tekrar deneyiniz.\n");
        }
    } while (giris != 0);
}
void musteri_menu(Customer *customer_list) {
    int giris;
    char tracking_number[20];
    do {
        printf("\nMusteri Menusu:\n");
        printf("1 - Kargo Takip Numarasi ile Gonderimi Sorgula\n");
        printf("0 - Ana Menuye Don\n");
        printf("Secim: ");
        scanf("%d", &giris);

        switch (giris) {
            case 1:
                 kargo_sorgulama(customer_list);
                break;
            case 0:
                printf("Ana Menuye donuluyor...\n");
                break;
            default:
                printf("Hatali secim. Lutfen tekrar deneyiniz.\n");
        }
    } while (giris != 0);
}

int main() {
    CityNode *root = create_city(1, "Merkez", 0);

    // Şehirleri eklemek için fonksiyonu çağırıyoruz
    add_cities(root);

    // Ağacı görselleştir
   printf("Kargo Rotalama Agaci:\n");
    display_tree(root, 0);

    Customer *customer_list = NULL;
    prefill_customers(&customer_list, root);

    int giris;
     do {
        printf("\nLutfen yapmak istediginiz islemi seciniz:\n");
        printf("1 - Personel\n");
        printf("2 - Musteri\n");
        printf("0 - Cikis\n");
        printf("Secim: ");
        scanf("%d", &giris);

        switch (giris) {
            case 1:
                personel_menu(&customer_list, root);
                break;
            case 2:
                musteri_menu(customer_list);
                break;
            case 0:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Hatali secim. Lutfen tekrar deneyiniz.\n");
        }
    } while (giris != 0);
    free_tree(root);
free_customers(customer_list);

    return 0;
}

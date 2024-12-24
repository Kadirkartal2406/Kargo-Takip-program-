Kargo Takip Sistemi
Kullanılan Veri Yapıları
Proje kapsamında kullanılan veri yapıları ve bunlarla ilgili açıklamalar aşağıda yer almaktadır.
1. Ağaç Veri Yapısı (Tree) - CityNode
Şehirler arasındaki ilişkileri tutmak için ağaç veri yapısı kullanılmıştır. Her şehir, bir düğüm (node) olarak temsil edilir ve her düğüm alt şehirler ve kardeş şehirlerle bağlantılıdır. Bu yapı, şehirlerin ağaç şeklinde organize edilmesini sağlar.
CityNode Yapısı
Her bir şehir, CityNode türünde bir yapı ile temsil edilir. Bu yapı, şehre ait temel bilgileri ve şehirler arası bağlantıları içerir.
Fonksiyonlar:
•	create_city: Yeni bir şehir düğümü oluşturur.
•	add_city: Bir şehre alt şehir ekler.
•	display_tree: Şehir ağacını derinlikli olarak ekrana yazdırır.
2. Bağlı Liste (Linked List) - Customer ve Shipment
Müşteri ve Gönderi bilgilerini saklamak için bağlı liste veri yapısı kullanılmıştır. Bu, her müşterinin birden fazla gönderiyi tutabilmesini sağlar. Her bir müşteri bir Customer düğümüne, her gönderi ise bir Shipment düğümüne karşılık gelir.
Customer (Müşteri Düğümü)
Müşteri bilgileri, birden fazla gönderiyi tutabilmek için bağlı liste kullanır. Her müşteri, gönderileriyle birlikte bir Customer düğümü içinde yer alır.
Shipment (Gönderi Düğümü)
Gönderi bilgileri, bağlı liste elemanı olarak tutulur. Her gönderi, bir Shipment düğümü içerir ve her gönderi, bağlı listeyle ilişkilendirilir.
Fonksiyonlar:
•	add_shipment: Bir müşteriye yeni gönderi ekler.
3. Ağaç ve Bağlı Liste Kullanımı:
•	Ağaç Veri Yapısı (Tree): Şehirler bir ağaç yapısında düzenlenmiştir. Bu sayede şehirler arası hiyerarşik bir ilişki kurulur. Alt şehirler, ana şehirlerin çocukları olarak tanımlanır.
•	Bağlı Liste (Linked List): Müşteriler ve gönderiler birbirine bağlı liste ile organize edilmiştir. Her müşteri birden fazla gönderi yapabilir ve bu gönderiler sırasıyla bağlı liste şeklinde tutulur.
Fonksiyonlar
Şehir Yönetimi Fonksiyonları
1.	create_city
Yeni bir şehir düğümü oluşturur ve verilen şehir bilgilerini atar.
2.	add_city
Verilen bir şehir düğümüne alt şehir ekler. Yeni bir alt şehir, verilen şehre bir çocuk (child) olarak eklenir.
3.	add_cities
"Merkez" şehri ile başlayan ve onun altındaki şehirlerle bir ağacın tamamını ekler.
4.	display_tree
Şehir ağacını görselleştirir ve her bir şehri derinliğine göre sıralayarak ekrana yazdırır.
5.	calculate_travel_time
Kullanıcı tarafından verilen şehir adına ulaşmak için gereken seyahat süresini hesaplar.
6.	free_tree
Şehir ağacındaki tüm düğümleri serbest bırakır ve belleği temizler.
Müşteri ve Gönderi Yönetimi Fonksiyonları
1.	add_customer
Yeni bir müşteri ekler. Müşteri, verilen ID ve isimle listeye eklenir.
2.	generate_tracking_number
Rastgele bir takip numarası üretir. Takip numarası, hem harfleri hem de sayıları içerir.
3.	add_shipment
Bir müşteriye yeni bir gönderi ekler. Gönderi, tarih sırasına göre eklenir.
4.	display_shipment_history
Bir müşterinin tüm gönderim geçmişini yazdırır.
5.	display_customer
Verilen müşteri ID'sine sahip müşteri bilgilerini ve gönderim geçmişini ekrana yazdırır.

6.	musteri_bilgileri
Yeni bir müşteri ekler ve kullanıcıdan ad ve soyad bilgilerini alır.
7.	gonderim_ekle
Bir müşteriye yeni bir gönderi ekler ve kullanıcıdan gerekli bilgileri alır.
8.	musteri_goruntuleme
Kullanıcıdan bir müşteri ID'si alır ve o müşterinin bilgilerini görüntüler.
9.	display_all_customers
Tüm müşterileri listeler ve bir müşterinin gönderim geçmişini gösterir.
10.	display_all_shipments
Tüm gönderileri listeler.
11.	kargo_sorgulama
Kullanıcıdan bir takip numarası alır ve ilgili kargo bilgilerini görüntüler.
Diğer Yardımcı Fonksiyonlar
1.	is_valid_address
Verilen teslimat adresinin geçerli olup olmadığını kontrol eder.
2.	free_customers
Müşterilerin belleğini temizler.


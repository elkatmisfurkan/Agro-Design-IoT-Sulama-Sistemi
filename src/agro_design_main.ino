/*
 * --------------------------------------------------------------------------
 * PROJE BAŞLIĞI: Agro-Design: IoT Tabanlı Otonom Sulama Sistemi (Prototip)
 * --------------------------------------------------------------------------
 * * PROJE YÜRÜTÜCÜSÜ: Furkan Elkatmış
 * KONUM: Muş, Türkiye
 * TARİH: Aralık 2025
 * KAPSAM: TÜBİTAK 2209-A Araştırma Projesi
 * * AÇIKLAMA:
 * Bu yazılım, analog toprak nem sensöründen gelen veriyi (0-1023) okur.
 * Belirlenen kuruluk eşik değerinin (THRESHOLD) üzerine çıkıldığında,
 * toprağın kuruduğu anlaşılır ve röle tetiklenerek su pompası çalıştırılır.
 * * DONANIM PIN YAPISI:
 * - Toprak Nem Sensörü (Analog): A0 Pini
 * - Röle Modülü (Pompa Kontrol): Dijital 7. Pin
 * - Seri Haberleşme (Debug): 9600 Baud Rate
 * */

// --- SABİT DEĞERLER VE PIN TANIMLAMALARI ---
#define SENSOR_PIN A0      // Toprak nem sensörünün bağlı olduğu Analog pin
#define ROLE_PIN 7         // Su pompasını kontrol eden Rölenin bağlı olduğu Dijital pin

// --- KALİBRASYON AYARLARI ---
// Not: Sensör 0 (Çok Islak) ile 1023 (Çok Kuru) arasında değer verir.
// Muş iklimi ve Sümbül bitkisinin nem ihtiyacına göre bu değeri güncelleyin.
const int KURULUK_ESIK_DEGERI = 750; 

// --- DEĞİŞKENLER ---
int anlikNemDegeri = 0;    // Sensörden okunan ham veri

void setup() {
  // Seri haberleşmeyi başlat (Bilgisayardan değerleri görmek için)
  Serial.begin(9600);
  
  // Pin modlarını ayarla
  pinMode(SENSOR_PIN, INPUT);
  pinMode(ROLE_PIN, OUTPUT);
  
  // Başlangıçta pompayı kapalı tut (Güvenlik önlemi)
  digitalWrite(ROLE_PIN, LOW); // Röle tipine göre LOW veya HIGH olabilir
  
  Serial.println("--- Agro-Design Sistemi Baslatiliyor ---");
  Serial.println("Sensör Kalibrasyonu ve Donanim Kontrolü Yapiliyor...");
  delay(2000); // Sistemin oturması için 2 saniye bekle
}

void loop() {
  // 1. ADIM: VERİ TOPLAMA
  // Toprak nem sensöründen analog veriyi oku
  anlikNemDegeri = analogRead(SENSOR_PIN);
  
  // Okunan değeri seri port ekranına yazdır (Raporlama ve Debug için)
  Serial.print("Anlik Toprak Nemi (0-1023): ");
  Serial.print(anlikNemDegeri);
  
  // 2. ADIM: KARAR MEKANİZMASI (Algoritma)
  // Eğer okunan değer Eşik Değerden BÜYÜKSE toprak KURU demektir.
  if (anlikNemDegeri > KURULUK_ESIK_DEGERI) {
    
    // EYLEM: SULAMAYI BAŞLAT
    Serial.println(" | DURUM: Toprak KURU -> Pompa AKTİF (Sulama Yapiliyor)");
    digitalWrite(ROLE_PIN, HIGH); // Röleyi tetikle (NO hattını kapat)
    
  } else {
    
    // EYLEM: SULAMAYI DURDUR / BEKLE
    Serial.println(" | DURUM: Toprak NEMLİ -> Pompa PASİF (Beklemede)");
    digitalWrite(ROLE_PIN, LOW);  // Röleyi kapat
  }
  
  // 3. ADIM: KARARLILIK GECİKMESİ
  // Sensör verisindeki anlık dalgalanmaları önlemek için bekle
  delay(1000); // 1 saniyede bir ölçüm yap
}
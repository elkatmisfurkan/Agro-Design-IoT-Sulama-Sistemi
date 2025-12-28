# 🌱 Agro-Design: IoT Tabanlı Otonom Sulama Sistemi (Prototip)

## 📌 Proje Hakkında
Bu proje, Muş ili iklim koşullarında iç mekan bitki yetiştiriciliğini optimize etmek amacıyla geliştirilmiş otonom bir sulama sistemidir. Sistem, toprak nem sensöründen aldığı verileri işleyerek bitkinin su ihtiyacına göre sulama ünitesini (pompayı) otomatik olarak devreye sokar.

**Proje Yürütücüsü:** Furkan Elkatmış  
**Konum:** Muş, Türkiye  
**Durum:** Prototip Tamamlandı / Test Aşamasında

---

## 🛠 Donanım Mimarisi
Sistem aşağıdaki bileşenler üzerine kurulmuştur:
- **Mikrodenetleyici:** Arduino Uno R3
- **Sensör:** Analog Toprak Nem Sensörü
- **Aktüatör:** 5V Dalgıç Su Pompası + Röle Modülü (NO Konfigürasyonu)
- **Güç Yönetimi:** Harici 6V Pil Bloğu (İzole Güç Kaynağı)

---

## 🌾 Botanik Süreç ve Kriz Yönetimi
Proje sürecinde iki aşamalı bir botanik test uygulanmıştır:

1.  **Fesleğen (Basil) Denemesi:** Lojistik süreçte yaşanan "soğuk stresi" ve "nakil şoku" nedeniyle ilk materyallerde kayıp yaşanmıştır. (Bkz: `img` klasörü)
2.  **Sümbül (Hyacinth) Entegrasyonu:** Bölgenin kış koşullarına (soğuklanma isteğine) uygun olan Sümbül soğanlarına geçiş yapılmış ve "yüzey ekim tekniği" ile sisteme entegre edilmiştir.

---

## 📂 Klasör Yapısı
- **`src/`**: Sistemin C++ tabanlı Arduino kaynak kodları.
- **`docs/`**: TÜBİTAK 2209-A Sonuç Raporu ve teknik dökümanlar.
- **`img/`**: Proje sürecine ait fotoğraflar (Devre şeması, bitki gelişim evreleri).

---

## 🚀 Kurulum ve Kullanım
1. `src` klasöründeki `.ino` dosyasını Arduino IDE ile açın.
2. Sensör kalibrasyon değerlerini (Threshold) kendi toprağınıza göre güncelleyin.
3. Kodu karta yükleyin ve harici güç kaynağını açın.

---
© 2025 Agro-Design Project.

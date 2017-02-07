kebutuhan:
	windows:
		xampp / web server lain
	linux/mac/other OS:
		lampp / web server lain
	gedget:
		smartphone tipe apa pun, tapi yang bisa dibuat wifian

	wifi/mifi/hostpot (dari smartphone)

nb: jangan hidupkan hostpot dari gedget anda,
karena gedget yang saya tulisakan diatas untuk melihat data dari chip esp nanti

cara menjalankan:
1. kopi folder web_api_esp ke foler web root anda
	contoh:
		windows:
			kopi kan ke local disk c -> xampp -> htdocs
		linux/mac/other OS:
			untuk penginstallan web server secara terpisah
			kopi kan ke var -> www -> html
			untuk penginstallan web server secara package seperti lampp
			kopikan ke opt -> lampp -> htdocs

2. test web api anda apakah sudah berhasil atau belum
	buka web browser anda lalu ketikan di url seperti berikut
	http://localhost/web_api_esp/index.php/welcome/testing
	jika muncul tabel ditengah, maka anda sudah berhasil membuat web api

3. buka arduino anda dan buka kode WiFiClient_for_stnk

4. cari tulisan {//Deklarasi Wifi untuk update data} di arduino tsb
	lalu dibawahnya isikan nama wifi/hostpot anda beserta passwordnya

5. cek ip yang anda dapat dilaptop anda
	contoh:
		windows:
			buka cmd lalu ketikan ipconfig
			maka anda akan melihat banyak tulisan
			lalu cari tulisan 192.168.xxx.xxx
		linux/mac/other OS:
			buka terminal/iTerm lalu ketikan ifconfig
			maka anda akan melihat banyak tulisan
			lalu cari tulisan 192.168.xxx.xxx
			
6. cari tulisan {//Deklarasi web api untuk mengambil data} di arduino tsb
	lalu ganti nilai variabel host dengan ip laptop yang anda dapat tadi

7. upload sketch nya

8. buka simulator arduino yang berada di pojok kanan atas

9. tunggu berhenti

10. lalu konek kan smartphone anda ke wifi test_esp dengan password 123456789

11. buka browser di smarthpone anda lalu tulisakan di url seperti berikut, http://192.168.1.4

jika tidak berhasil silahkan konsultasikan ke email dan nomor dibawah ini
email: bayu.bayusaputra11@gmail.com
nomor: 087855979144

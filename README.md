# VeriYapilari_LAB4

# Konu: Grafta Arama   Problem:  Labirent Problemi  
 
Bu ödevde, verilen bir N sayısı ve verilen bir NxN’lik labirent için, başlangıç hücresi (1,1)’den bitiş hücresi (N, N)’e yol olup olmadığını DFS(Depth First Search) yöntemi ile bulan bir algoritma tasarlanacaktır. DFS’yi rekürsif yaklaşım ile gerçekleştiriniz.  
 
Rekürsif DFS işlemi için yarı-kod aşağıdaki gibidir: DFS( to visit a vertex v in Graph G) {  Mark v as visited  for all neighbors w of v in Graph G    if w is not visited    DFS(to visit a vertex w in  Graph G) }   
 
Yapılacak İşlemler : NxN hücreden oluşan labirent  için bir matris kullanınız. Labirent matrisinde duvarları 0, açık yolları 1 ile gösteriniz.  Örneğin matrisin [1][2] değeri  0 ise 1. satır 2. sütündaki hücre duvardır. Her hücrenin kuzey, güney, doğu ve batı yönünde toplam 4 komşusu vardır.  Matrisin kenar hücrelerinin de 4 komşusu olabilmesi için (N+1)x(N+1)’lik bir matris tanımlayıp bu ek hücreleri duvar olarak tanımlayınız.  
 
İşlem adımları aşağıdaki gibidir: 1. İşleme (1,1) hücresinden başlayınız. 2. O anda işlenen (x,y) hücresini “gelindi” olarak işaretleyiniz. 3. Kuzey-(x,y+1)  yönünde duvar yoksa (x,y+1) hücresine giderek onun komşularına bakınız.  4. Doğu-(x+1,y)  yönünde duvar yoksa (x+1,y) hücresine giderek onun komşularına bakınız.  5. Güney-(x,y-1)  yönünde duvar yoksa (x,y-1) hücresine giderek onun komşularına bakınız.  6. Batı-(x-1,y)  yönünde duvar yoksa (x-1,y) hücresine giderek onun komşularına bakınız.  7. (NxN) hücresine gelindiyse işlem bitmiştir.   
 
Labirenti ekranda göstermek için aşağıdaki işaretleri kullanınız:  
Duvarlar : '-' ve '|'  Odalar : ' ' Odaların köşeleri :  '+', Başlangıç :  '*'  Çıkış :  'X'  İzlediği yol: ‘I’ 
Örneğin :       
 +-+-+-+-+-+-+-+ 
 |*|   | | |   | 
 + +-+ + + +-+ + 
 |I  |   |     | 
 + + + +-+ +-+ + 
 |I|   |     | | 
 + +-+-+ +-+-+ + 
 |I I    |     | 
 +-+ + +-+-+ +-+ 
 |  I I I I I X| 
 +-+-+-+-+-+-+-+ 

# Directory-Monitor
Il progetto richiede la creazione di un sistema di monitoraggio delle directory. Nello specifico, l’applicazione deve essere in grado di notificare l’eventuale creazione, modifica, e cancellazione di file all’interno della directory myDir (inizialmente vuota). Per fare ciò deve essere implementata una funzione “temporizzata” che ogni 3 secondi verifichi se lo stato dei file all’interno della directory è cambiato e un’interfaccia che riporti il log delle attività. La figura sottostante rappresenta un mockup dell’interfaccia.
![image](https://user-images.githubusercontent.com/101665044/190693585-27f2cb4c-7181-403b-8b07-2cf61b0d8fc8.png)

Si noti che ad ogni tipologia di azione (creazione, modifica o cancellazione) deve essere associata un’etichetta di colore differente (ad esempio, come nel mockup, creazione: verde, modifica: blu, cancellazione: rosso). Inoltre, l’interfaccia deve consentire di: 
• Salvare su file il log delle attività relative alla sessione corrente. 
• All’avvio dell’applicazione, se esistente, caricare il file contenente il log delle attività relative alle precedenti sessioni. 
• Ordinare le voci del log in base al: nome del file, tipo di evento o momento in cui è stata registrata l’azione.

Nota: Utilizzare la versione 5.12 o superiori della libreria Qt.

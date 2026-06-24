# Praktikum3-4

V2:
Im gegebenen Program ist CVocabTrainer direkt an die Klasse CRandomQuery gebunden. Die Methode startQuery() nimmt nämlich genau einen CRandomQuery* entgeegen also einen zeiger auf diesen einen konkreten Typ. Damit akzeptiert sie ausschließlich objekte dieser Klasse und keine andere.

Wollte man jetzt einen weiteren Abfragemodus ergänzen, etwa eine Klasse CSequentialQuery, die die Vokabeln der Reihe nach abfragt, ließe sich diese gar nicht an startQuery() übergeben Der Compiler würde den falschen Typ ablehnen. Man müsste also die Signatur von startQuery() anpassen und damit den bestehenden Code von CVocabTrainer verändern, genau das soll aber vermieden werden.

Der Grund dafür liegt darin, dass die Klassen keine gemeinsame Basisklasse besitzen. Es gibt keine übergeordnete Schnittstele, von der verscheidene Abfragemodi abgeleitet werden könnten und über die CVocabTrainer sie einheitlich ansprechen würde. 
Solange startQuery() mit einem konkreten Klassentyp statt mit einem abstrakten Schnittstellentyp arbeitet, fehlt die Möglichkeit zur Polymorphie und damit jede flexieble Erweiterbarkeit.

V3:
Swischen klasse so wie wir es im unterich gemacht haben damit man auswählen kann wie man seinen Karten sortirt haben will z.b.
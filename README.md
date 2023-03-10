# Conway's Game of Life in C

<table>
<tr><th>Ersteller</th><td>Nikolas Bodenmüller, Fabian Sigmund</td></tr>
<tr><th>Betreuer</th><td>Jonas Fritzsch, M.Sc.</td></tr>
<tr><th>Studiengang/Kurs</th><td>B. Sc. Informatik TINF22F</td></tr>
<tr><th>Anlass</th><td>Programmierprojekt</td></tr>
<tr><th>Bearbeitungszeitraum</th><td>03.02.2023 - 14.02.2023</td></tr>
<tr><th>Abgabedatum</th><td>14.02.2023</td></tr>
</table>

## Userdokumentation

Beim Starten des Programms wird dem Nutzer die Auswahl aus verschiedenen Mustern gegeben. Die Auswahl erfolgt durch Eingabe eines angezeigten Zeichens. Falls der Nutzer ein eigenes Startmuster festlegen will, kann er ein beliebiges anderes Zeichen eingeben. Falls der Nutzer eigene Koordinaten eingeben will, wird er gefragt wie viele Zellen er manuell eingeben will. Anschließend kann er dementsprechend viele Koordinatenpaare eintragen. Zuletzt muss noch ausgewählt werden, ob eine neue Generation automatisch oder beim Drücken einer Taste angezeigt wird. Um die Simulation zu beenden muss die Taste 'q' gedrückt werden.

## Entwicklerdokumentation

<table>
<tr><th>void setup()</th><td>Die Methode leert die Konsole, ruft die createBoard Methode für beide Boards auf und ruft die Methode select für die Abfrage der Startkonfiguration auf.<td></tr>
<tr><th>int checkNeighbours(int, int)</th><td>Der Funktion werden die Koordinaten des aktuellen Felds übergeben. Mit einer geschachtelten Schleife werden die 8 Nachbarfelder überprüft. Falls zu überprüfenden Felder außerhalb des Felds liegen würden, wird mithilfe einer selbst definierten Modulo Funktion das korrekte Feld am anderen Rand überprüft.</td></tr>
<tr><th>void select()</th><td>Es werden Auswahlmöglichkeiten in der Konsole ausgegeben. Der Nutzer kann entweder eine auswählen oder durch drücken einer anderen Taste eigene Koordinaten eingeben.</td></tr>
<tr><th>void setCustomCells()</th><td>Der Nutzer wird gefragt wie viele Koordinaten er eingeben will. Anschließend werden mithilfe einer Schleife dementsprechend viele Koordinaten eingelesen.</td></tr>
<tr><th>void printBoard()</th><td>Eine geschachtelte Schleife iteriert über das Spielfeld gibt jedes Zeichen aus und macht nach jeder Zeile einen Zeilenumbruch.</td></tr>
<tr><th>void cycle()</th><td>Beschreibt einenen Spieldurchlauf. Hierbei wird über das Feld iteriert und für jede Zelle die checkNeighbours Methode aufgerufen. Basierend auf der Antwort wird in einem zweiten Spielfeld die entsprechende Zelle auf tot oder lebendig gesetzt. Anschließend wird das Hauptspielfeld mit dem temporären überschrieben. </td></tr>
<tr><th>void createBoard(char[BOARDHEIGHT][BOARDWIDTH])</th><td>Der Funktion wird ein character Array als Parameter übergeben. Dieses wird mit Leerzeichen ausgefüllt.</td></tr>
</table>



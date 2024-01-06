
ADAM ŠTROBL (strobad1)
Projekt B6B36PCC




===========================
PROJEKT HLEDÁNÍ MIN
===========================










POPIS ZADANI SAMOTNEHO PROJEKTU: 

https://cw.fel.cvut.cz/wiki/courses/b6b36pcc/ukoly/sem_prace

https://cw.fel.cvut.cz/wiki/courses/b6b36pcc/ukoly/sem_tvorhru


Odevzdání, termín a hodnocení
Semestrální práce se odevzdává přes GitLab a email cvičícímu. Soubory, které odevzdáváte by měly být všechny na fakultním GitLabu, email pak slouží k notifikaci učitele, že jste připraveni semestrálku odevzdat, a kterou verzi (commit hash nebo tag) semestrálky odevzdáváte.

Váš repozitář na GitLabu pak musí obsahovat:

zdrojové soubory,
CMakeLists.txt, dle kterého se dá semestrálka postavit
vzorová vstupní data (pokud je program přijímá)
Zpráva k vaší semestrálce v souboru Readme musí obsahovat:
	popis vašeho zadání,
	popis vaší implementace,
	popis funkčnosti a ovládání aplikace,
	výsledky běhu programu a naměřené časy při porovnání jedno- a více- vláknové verze
	
Povolené formáty pro zprávu k semestrálce jsou: textový dokument, Markdown nebo rozumné PDF



---



DRUHOTNE ZADANI(checklist):
* Kód
  * Obsahuje váš kód CMakeLists.txt přes který se vaše semestrálka dá postavit?
  * Je implementována nápověda (argument programu --help)?
* Použití vláken pro vyšší bodové hodnocení (PROJEKTU MINESWEEPER SE NETYKA)
  * Používá váš kód alespoň tři vlákna, která správně komunikují?
  * Nepoužívá váš kód rozšíření jazyka? (Například OpenMP, VLA)
  * Nepoužívá váš kód nepřenosné knihovny (Například POSIX, Win32, filesystem)
* Testování
  * Obsahuje vaše řešení popis způsobů a postupů testování? Obsahuje příklady testů, které jste prováděli?
  * Zkontrolovali jste svoje řešení s využitím vhodného analytického nástroje (valgrind, dr. Memory apod.)?
* Zpráva
  * Obsahuje vaše zpráva hash commitu (nebo tag), vůči kterému byla napsaná?
  * Obsahuje vaše zpráva popis zadání? 
  * Obsahuje vaše zpráva popis ovládání hry?
  * Obsahuje vaše zpráva popis možností a způsobů nastavení hry?
  * Máte proměnné a funkce programu řádně zdokumentovány? Jsou všude doplněny komentáře?





---

ZADANI PO DOMLUVE S CVICICIM:

Projekt zahrnuje implementaci klasické hry Hledání Min (Minesweeper). Hra je založena na odhalování políček na hrací desce, přičemž některá políčka mohou obsahovat miny. Cílem hráče je odhalit všechna políčka bez min a označit políčka, kde se podle jeho odhadu nachází mina.





----------------------------




POPIS PRAVIDEL:

Hrací deska je reprezentována dvourozměrným polem (matice), kde každé políčko může být buď prázdné, obsahovat minu nebo mít přiřazené číslo označující počet okolních min.

Hráč začíná hru tím, že vybere počáteční políčko, které odhalí. Toto první odhalení nikdy neskonci tak, aby hráč trefil minu.
Po odhalení políčka se zobrazí číslo, které informuje o počtu min v jeho okolí.
Hráč může označit políčka, kde se podle jeho odhadu nachází mina, přidáním vlajky (vlajku může i kdykoliv odstranit).
Hráč může odhalovat další políčka nebo odstraňovat vlajky podle svého uvážení.

Hra končí výhrou, pokud hráč odhalí všechna bezpečná políčka (bez min) a označí všechna políčka s minami vlajkami.
Hra končí prohrou, pokud hráč odhalí políčko s minou.

Před samotným zahájením hry si hráč může vybrat rozměry hrací desky (šířku a výšku) a počet min. To ovlivňuje obtížnost hry.





----------------------------


DOKUMENTACE A KOMENTARE:

Kód projektu je dobře zdokumentovaný pomocí javadoc komentářů v .hpp souborech a obyčejných komentářů v .cpp souborech, aby bylo snadné pochopit logiku a funkce. Každá důležitá proměnná i funkce programu je řádně zdokumentována v komentářích.


----------------------------

OVLÁDÁNÍ  HRY

Následujte instrukce, které říká hra, případně se podívejte na vzorová vstupní data na spodku README. Pokud se ztratíte, můžete na kterékoliv obrazovce napsat [help] (bez hranatých závorek), a vysvětlí se, jaké máte možnosti.



---

PODROBNÉ POPSANÍ OVLÁDÁNÍ:
	přípravná fáze:
		zvolení si velikosti herní desky : dvě čísla oddělena mezerou v rozmezí 3 - 25
		zvolení si počtu min: počet min je v rozsahu 1 až do (šířka desky * výška desky) - 1.

	----

	hra:
      - Vybrání si místa, kde odhalí hráč první čtvereček: dvě čísla ohraničená šířkou a výškou hracího pole.
      - Rozhodnutí, jestli chce hráč položit nebo odstranit vlajku, která naznačuje odhadovanou pozici miny hráčem: y/n (ano/ne).
        - Pokud hráč zvolí 'y', vybere si pozici x a y souřadnic v rozmezí hracího pole a tím odstraní nebo přidá vlajku, herní cyklus se opakuje.


Hráč vyhrává, jakmile položí vlajku na všechna políčka s minami a odhalí všechna políčka, na kterých miny nebyly. Prohrává, jakmile odhalí minu.


----

Nastavení a možnosti hry:

Hráč si může zvolit rozměry hracího pole a počet min. Postup je vysvětlen v sekci umístěné nad tímto odstavcem. V jistém omezení lze nastavit šířku hracího pole 3 - 25 políček oběma směry
Tudíž maximální šířka hracího pole je 25*25 a maximální počet min (25^2) - 1.




----------------------------






POPIS IMPLEMENTACE:

Celý program běží na CMake, a git byl používán pro zachování dat.

Pro implementaci jsem využil převážně knihovny standard.
Některé importy, které jsem využil, byly: <iostream>, <sstream>, <regex>, <stack>, <iomanip>, <random> a <optional>.


Projekt je řízen hlavní třídou GameManager - ta ovládá celkový běh hry a vlastní instanci hracího pole.

GameManager tedy dovoluje hráči zadat informace o tom, jaké by chtěl vytvořit herní pole, kde odhalovat políčka nebo pokládat vlaječky a případně i hrát znovu.
Board je deska a uživatel s ní přímo sám nepracuje, ale vždy prostřednictvím třídy GameManager. Deska si udržuje vektor vektorů struktur Cell aneb políček. Struktura Cell zachovává informace o stavu políčka. Jestli obsahuje číslo, minu anebo zdali je prázdný. Zároveň také svůj stav, jestli je políčko viditelné, skryté nebo pod vlajkou.
Struct Cell zachovava informace o stavu policka. jestli obsahuje cislo, minu anebo zdali je prazdny. Zaroven taky svuj stav, jestli je policko viditelne, skryte, nebo pod vlajkou.


Klíčové části jsou tedy samotný herní cyklus - game loop - který vlastní GameManager, kde hráč začíná skutečně zadávat své vlastní inputy interakce s hracím polem, a druhá klíčová část je vlastně celá třída Board.

V pozdější implementaci by se dal projekt rozšířit implementací raw inputu, trošku přeorganizování kódu v metodách apod.

V neposlední řadě je třeba zmínit argument --help, který je viditelný v třídě main a popisuje anglicky základní pravidla hry.





----------------------------





TESTOVANI:

Testování jsem provedl za pomocí Catch2, podobně, jako nám bylo ukázáno v domácích úkolech během semestru. Veškeré testy se vyskytují v třídě test1.cpp.

Pojal jsem zde unit testování i hlubší end to end testy ke konci souboru.

Udělal jsem menší sadu testů, která relativně hluboce kontroluje chod hry, jsou v dispozici v repozitáři společně se zbytkem projektu.

V test-casu Scenario 1 testuji:
- náhodnou distribuci min po desce 10x10.
- Konstruktor desky.


v test casu End game state - requirement testing testuji, jestli hra detekuje kdy ma skončit, tj. metody isBoardCleared() a isCellMine(), které vlastni board

v test casu  Simulate player input at runtime provadim jakesi end to end testy které používají seed pro muj generator aby zabranili nahodnemu rozlozeni min a iStringStream na nahrazeni uzivatelskeho inputu. Projdu tak jednu vyhranou a jednu prohranou hru a jeste overim osetrenost uzivatelskeho inputu




----------------------------



PAMETOVY MANAGEMENT:

Dále jsem prošel důkladně Valgrindem celý chod aplikace a již se neobjevují žádné závadné bloky paměti při spouštění a běhu programu.
Z paměťového hlediska by program měl být neprůstřelný. Nikde jsem nepoužil new, a používám smart pointery všude, kde možno.

----------------------------

VÝSLEDKY BĚHU PROGRAMU (pokud musi kapitola být přítomna i u jednovlaknoveho programu):
Program vždy skončí, jak očekáváno, bez paměťových závad skončením hráče hry se zprávou "Quitting game..."




----------------------------

POZNAMKY:

Maximální rozměr byl zvolen 25 z důvodu, že vyšší se mi zalomil v mé IDE Clion, a nevěděl jsem, v čem a jak bude pak můj program testován. Ze stejného důvodu nepoužívám ANSI Escape kódy pro barvení desky ani speciální znaky nebo emoji pro bomby atd. při tisknutí desky, nebylo to v IDE poté čitelné.



==========================================================================


VZOROVA VSTUPNI DATA


v kroku kdy vybirame velikost doplnit: 3 3

pocet min: 1



zbytek hry hrat dle libosti.

od metody gameloop pak muze vypadat hracuv input treba takhle


                "1 1" // first reveal
                "n"
                "2 2" second reveal

                "y" // flagged the mine
                "1 2"

                "n"
                "0 0" //...
                "n"
                "2 1"
                "n"
                "0 1"
                "n"
                "0 2"
                "n"
                "2 1"
                "n"
                "2 2"


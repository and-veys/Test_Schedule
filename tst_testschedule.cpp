#include <QtTest>
#include "../Schedule/qml_schedule.h"

class TestSchedule : public QObject
{
    Q_OBJECT

public:
    TestSchedule();
    ~TestSchedule();

private slots:
    void testNote();
    void testSchedule();
    void testTimeSchedule();
};

TestSchedule::TestSchedule()
{

}

TestSchedule::~TestSchedule()
{
   QFile::remove("test.json");

}

void TestSchedule::testNote()
{
    Note * note = new Note("Задание_1", QDate(2023, 2, 3), 8);
    QVERIFY(note);
    QList<QString> res = note->getParamsString();
    QCOMPARE(res[0], "Задание_1");
    QCOMPARE(res[1], "03.02.2023");
    QCOMPARE(res[2], "8");
    delete(note);

}

void TestSchedule::testSchedule()
{
    QML_Schedule * sch = new QML_Schedule("test.json");
    QVERIFY(sch);
    QList<int> date;
    date << 5 << 10 << 2025;
    sch->setNote("Задание_N", date, 6);
    delete(sch);
    sch = new QML_Schedule("test.json");
    QList<Note> * notes = sch->getListNotes();
    QList<QString> res = notes->last().getParamsString();
    QCOMPARE(res[0], "Задание_N");
    QCOMPARE(res[1], "05.10.2025");
    QCOMPARE(res[2], "6");
    delete(sch);
}

void TestSchedule::testTimeSchedule() {
    QBENCHMARK(testSchedule());
}



QTEST_APPLESS_MAIN(TestSchedule)

#include "tst_testschedule.moc"

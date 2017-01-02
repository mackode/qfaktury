#ifndef MainWindow_H
#define MainWindow_H
#include <QtWidgets/QMainWindow>
#include <QKeyEvent>
#include "Settings.h"
#include "ui_MainWindow.h"

#include "IDataLayer.h"


class MainWindow: public QMainWindow, public Ui::MainWindow {

Q_OBJECT
public:
	MainWindow(QWidget *parent);
	~MainWindow();
	static void insertRow(QTableWidget *t, int row);

	IDataLayer *dl;
public slots:
	void tableClear(QTableWidget * tab);
	void tabChanged(QWidget * aaa);
	void rereadHist();
	void aboutQt();
	void oProg();
	void editFHist();
	void delFHist();
	void daneFirmyClick();
	void settClick();
	void kontrClick();
	void kontrDel();
	void kontrEd();
	void newFra();
	void newPForm();
	void newKor();
	void newDuplikat();
	void newFBrutto();
	void newFRachunek();
	bool close();
	void pomoc();
	void reportBug();
	void towaryDodaj();
	void towaryUsun();
	void towaryEdycja();
	void mainUpdateStatus(QTableWidgetItem *item);
	void showTableMenuT(QPoint p);
	void showTableMenuK(QPoint p);
	void showTableMenuH(QPoint p);
	void pluginSlot();
	void pluginInfoSlot();
	void keyPressEvent(QKeyEvent * event);
private:
	QString workingDir; // should be deprecated
	QMap<int, QString> customActions;
	void saveColumnWidth();
	bool applyFiltr(QString);
	void init();
	bool firstRun();
	void saveAllSett();
	void saveAllSettAsDefault();
	void setupDir();
	void readHist();
	void readKontr();
	void readTw();
protected:
	virtual void loadPlugins();
};
#endif

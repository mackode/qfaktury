#ifndef Korekta_H
#define Korekta_H
#include <QtWidgets/QDialog>

#include "ui_Faktura.h"
#include "Faktura.h"

#include "ConvertAmount.h"
#include "Settings.h"
#include "InvoiceData.h"


class Korekta: public Faktura {
Q_OBJECT
public:
	Korekta(QWidget *parent, IDataLayer *dl);
	virtual ~Korekta();
	bool editMode;
	virtual void korektaInit(bool mode); // called outside
	virtual void readCorrData(QString fraFile);
public slots:
	// to be overwritten in child class
	virtual void backBtnClick();
	virtual bool saveInvoice();
	virtual void makeInvoice();
	virtual void canQuit();
protected:
	InvoiceData *invData;
	QComboBox *reasonCombo;
	QLabel *labelReason1;
	// virtual QString getGroupedSums();
	virtual void makeInvoiceSummAll();
	virtual void makeInvoiceSumm();
	virtual void makeInvoceProductsTitle(short a);
	virtual void makeBeforeCorrProducts();
	virtual void makeBeforeCorrSumm();
	InvoiceData *createOriginalInv();
	virtual void setIsEditAllowed(bool isAllowed);
	virtual void calculateDiscount();
	virtual void calculateSum();
	double origDiscTotal, origNettTotal, origGrossTotal;
	double diffTotal;
	virtual void calculateOneDiscount(int i);
	virtual QString getInvoiceTypeAndSaveNr();

};
#endif

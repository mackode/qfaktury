#ifndef Faktura_H
#define Faktura_H
#include <QtWidgets/QDialog>
#include <QDomElement>
#include <QDomDocument>
#include <QPrinter>

#include "ConvertAmount.h"
#include "Settings.h"

#include "CustomPaymData.h"

#include "IDataLayer.h"

#include "ui_Faktura.h"

class Faktura: public QDialog, public Ui::Faktura {
Q_OBJECT
public:
	Faktura(QWidget *parent, IDataLayer *dl);
	virtual ~Faktura();
	void init();
	void readData(QString fraFile, int co);
	QString fName, ret;
	bool pforma, kAdded;
	virtual void setIsEditAllowed(bool isAllowed);
	void keyPressEvent(QKeyEvent * event);

	virtual void calculateOneDiscount(int a);
public slots:
	void getCustomer();
	virtual void addTow();
	virtual void discountChange();
	void delTowar();
	void editTowar();
	void tableActivated ( QTableWidgetItem * item );
	void textChanged(QString someStr);
	void payTextChanged(QString someStr);
	void dateChanged (QDate someDate);
	virtual void discountConstChange(); // Overwritten in FakturaBrutto
	// to be overwritten in child class
	virtual void backBtnClick();
	virtual void canQuit();
	virtual bool saveInvoice();
	virtual void makeInvoice();
	void printSlot(QPrinter*);
	void kontrClick();
protected:
	IDataLayer *dataLayer;
	QString lastInvoice, invoiceType;
	double discountTotal, nettTotal, grossTotal;
	bool isEdit;
	bool canClose;
	bool saveFailed;
	CustomPaymData *custPaymData;
	QStringList fraStrList;
	QString numbersCount(int in, int x);
	int type;
	virtual void calculateDiscount();
	virtual void calculateSum();
	QString getGroupedSums();
	void saveColumnsWidth();
	virtual void makeInvoiceHeadar(bool sellDate, bool brakePage, bool original);
	virtual void makeInvoiceBody();
	virtual void print();
	virtual void makeInvoiceProducts();
	virtual void makeInvoiceSumm();
	virtual void makeInvoiceSummAll();
	virtual void makeInvoiceProductsHeadar();
	virtual void makeInvoiceFooterHtml();
	virtual void makeInvoiceHeadarHTML();

	virtual void setData(InvoiceData &invData);
	virtual void getData(InvoiceData invData);

	void makeInvoiceFooter();

	virtual QString getInvoiceTypeAndSaveNr();
	bool validateForm();

};
#endif

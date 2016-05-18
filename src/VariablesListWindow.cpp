/// @author Cedric Boudinet
/// @license GNU GPL Version 3
///
/// Distributed under the GNU GPL version 3 License
/// (See accompanying file LICENSE or copy at
/// http://www.gnu.org/licenses/)
///
#include "VariablesListWindow.h"
#include "iec61850Exp_fun.h"
#include <QGridLayout>
#include <QDialogButtonBox>
#include <QListWidget>
#include <iostream>
#include "iec61850Exp_fun.h"
#include "MmsValueWrapper.h"
VariablesListWindow::VariablesListWindow(QWidget *parent, IedConnection iedCon) : QDialog(parent), _iedCon(iedCon)
{
	QGridLayout *layout = new QGridLayout;
	setWindowTitle(tr("Variable list"));
	setModal(true);
	QDialogButtonBox * buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok| QDialogButtonBox::Cancel);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(onOK()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	variableListWidget=new QListWidget(this);
	variableListWidget->setSelectionMode( QAbstractItemView::ExtendedSelection );
	layout->addWidget(variableListWidget,1,0,1,1);
	layout->addWidget(buttonBox,2,0,1,1);
	setLayout(layout);
	resize(400, 300);
	_VariablesList = getVariableList(iedCon);
	for(std::vector<MmsValueWrapper>::iterator it =_VariablesList.begin();it!=_VariablesList.end();it++)
		variableListWidget->addItem(QString(it->getDispName().c_str()));
}


void VariablesListWindow::onOK()
{
	accept();
}

QStringList VariablesListWindow::getSelection()
{
	QStringList selection;
	QList<QListWidgetItem *> curList = variableListWidget->selectedItems();
	for (int i = 0; i < curList.size(); ++i)
	{
		selection.append(curList.at(i)->text());
	}
	return selection;

}

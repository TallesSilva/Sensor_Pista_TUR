# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'untitled.ui'
#
# Created by: PyQt5 UI code generator 5.11.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(484, 474)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.verticalLayout_9 = QtWidgets.QVBoxLayout(self.tab)
        self.verticalLayout_9.setObjectName("verticalLayout_9")
        self.formLayout_2 = QtWidgets.QFormLayout()
        self.formLayout_2.setObjectName("formLayout_2")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.Iniciar = QtWidgets.QPushButton(self.tab)
        self.Iniciar.setObjectName("Iniciar")
        self.verticalLayout_3.addWidget(self.Iniciar)
        self.Finalizar = QtWidgets.QPushButton(self.tab)
        self.Finalizar.setObjectName("Finalizar")
        self.verticalLayout_3.addWidget(self.Finalizar)
        self.formLayout_2.setLayout(0, QtWidgets.QFormLayout.LabelRole, self.verticalLayout_3)
        self.lcdNumber = QtWidgets.QLCDNumber(self.tab)
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        font.setStyleStrategy(QtGui.QFont.PreferAntialias)
        self.lcdNumber.setFont(font)
        self.lcdNumber.setObjectName("lcdNumber")
        self.formLayout_2.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.lcdNumber)
        self.label_6 = QtWidgets.QLabel(self.tab)
        self.label_6.setMinimumSize(QtCore.QSize(440, 200))
        self.label_6.setMaximumSize(QtCore.QSize(1920, 1270))
        self.label_6.setTabletTracking(False)
        self.label_6.setFocusPolicy(QtCore.Qt.NoFocus)
        self.label_6.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.label_6.setAutoFillBackground(True)
        self.label_6.setText("")
        self.label_6.setTextFormat(QtCore.Qt.AutoText)
        self.label_6.setPixmap(QtGui.QPixmap("WhatsApp Image 2018-08-18 at 20.49.58.jpeg"))
        self.label_6.setScaledContents(True)
        self.label_6.setWordWrap(True)
        self.label_6.setObjectName("label_6")
        self.formLayout_2.setWidget(1, QtWidgets.QFormLayout.SpanningRole, self.label_6)
        self.verticalLayout_9.addLayout(self.formLayout_2)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout()
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.label = QtWidgets.QLabel(self.tab)
        self.label.setMaximumSize(QtCore.QSize(100, 25))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(False)
        font.setWeight(50)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.verticalLayout_4.addWidget(self.label)
        self.lcdNumber_2 = QtWidgets.QLCDNumber(self.tab)
        self.lcdNumber_2.setMaximumSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.lcdNumber_2.setFont(font)
        self.lcdNumber_2.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.lcdNumber_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lcdNumber_2.setObjectName("lcdNumber_2")
        self.verticalLayout_4.addWidget(self.lcdNumber_2)
        self.horizontalLayout_2.addLayout(self.verticalLayout_4)
        self.verticalLayout_5 = QtWidgets.QVBoxLayout()
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.label_2 = QtWidgets.QLabel(self.tab)
        self.label_2.setMaximumSize(QtCore.QSize(100, 25))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(False)
        font.setWeight(50)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.verticalLayout_5.addWidget(self.label_2)
        self.lcdNumber_3 = QtWidgets.QLCDNumber(self.tab)
        self.lcdNumber_3.setMaximumSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.lcdNumber_3.setFont(font)
        self.lcdNumber_3.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.lcdNumber_3.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lcdNumber_3.setObjectName("lcdNumber_3")
        self.verticalLayout_5.addWidget(self.lcdNumber_3)
        self.horizontalLayout_2.addLayout(self.verticalLayout_5)
        self.verticalLayout_6 = QtWidgets.QVBoxLayout()
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.label_3 = QtWidgets.QLabel(self.tab)
        self.label_3.setEnabled(True)
        self.label_3.setMaximumSize(QtCore.QSize(100, 25))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(False)
        font.setWeight(50)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_6.addWidget(self.label_3)
        self.lcdNumber_4 = QtWidgets.QLCDNumber(self.tab)
        self.lcdNumber_4.setEnabled(True)
        self.lcdNumber_4.setMaximumSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.lcdNumber_4.setFont(font)
        self.lcdNumber_4.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.lcdNumber_4.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lcdNumber_4.setObjectName("lcdNumber_4")
        self.verticalLayout_6.addWidget(self.lcdNumber_4)
        self.horizontalLayout_2.addLayout(self.verticalLayout_6)
        self.verticalLayout_7 = QtWidgets.QVBoxLayout()
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.label_4 = QtWidgets.QLabel(self.tab)
        self.label_4.setMaximumSize(QtCore.QSize(100, 25))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(False)
        font.setWeight(50)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_7.addWidget(self.label_4)
        self.lcdNumber_5 = QtWidgets.QLCDNumber(self.tab)
        self.lcdNumber_5.setMaximumSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(True)
        font.setWeight(75)
        self.lcdNumber_5.setFont(font)
        self.lcdNumber_5.setFocusPolicy(QtCore.Qt.NoFocus)
        self.lcdNumber_5.setContextMenuPolicy(QtCore.Qt.NoContextMenu)
        self.lcdNumber_5.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.lcdNumber_5.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lcdNumber_5.setObjectName("lcdNumber_5")
        self.verticalLayout_7.addWidget(self.lcdNumber_5)
        self.horizontalLayout_2.addLayout(self.verticalLayout_7)
        self.verticalLayout_8 = QtWidgets.QVBoxLayout()
        self.verticalLayout_8.setObjectName("verticalLayout_8")
        self.label_5 = QtWidgets.QLabel(self.tab)
        self.label_5.setMaximumSize(QtCore.QSize(90, 25))
        font = QtGui.QFont()
        font.setFamily("Impact")
        font.setPointSize(20)
        font.setBold(False)
        font.setWeight(50)
        self.label_5.setFont(font)
        self.label_5.setObjectName("label_5")
        self.verticalLayout_8.addWidget(self.label_5)
        self.lcdNumber_6 = QtWidgets.QLCDNumber(self.tab)
        self.lcdNumber_6.setMaximumSize(QtCore.QSize(200, 100))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.lcdNumber_6.setFont(font)
        self.lcdNumber_6.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.lcdNumber_6.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.lcdNumber_6.setObjectName("lcdNumber_6")
        self.verticalLayout_8.addWidget(self.lcdNumber_6)
        self.horizontalLayout_2.addLayout(self.verticalLayout_8)
        self.verticalLayout_9.addLayout(self.horizontalLayout_2)
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QtWidgets.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.formLayout_4 = QtWidgets.QFormLayout(self.tab_2)
        self.formLayout_4.setObjectName("formLayout_4")
        self.label_7 = QtWidgets.QLabel(self.tab_2)
        self.label_7.setMinimumSize(QtCore.QSize(440, 67))
        self.label_7.setMaximumSize(QtCore.QSize(16776957, 16777215))
        self.label_7.setText("")
        self.label_7.setPixmap(QtGui.QPixmap("pista.jpeg"))
        self.label_7.setObjectName("label_7")
        self.formLayout_4.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.label_7)
        self.tabWidget.addTab(self.tab_2, "")
        self.verticalLayout_2.addWidget(self.tabWidget)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 484, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.Iniciar.setText(_translate("MainWindow", "Iniciar"))
        self.Finalizar.setText(_translate("MainWindow", "Finalizar"))
        self.label.setText(_translate("MainWindow", "A"))
        self.label_2.setText(_translate("MainWindow", "B"))
        self.label_3.setText(_translate("MainWindow", "C"))
        self.label_4.setText(_translate("MainWindow", "D"))
        self.label_5.setText(_translate("MainWindow", "E"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("MainWindow", "Tab 1"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("MainWindow", "Tab 2"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())


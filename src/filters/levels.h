/*
 * QArv, a Qt interface to aravis.
 * Copyright (C) 2012-2014 Jure Varlec <jure.varlec@ad-vega.si>
 * Andrej Lajovic <andrej.lajovic@ad-vega.si>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty or
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LEVELS_H
#define LEVELS_H

#include "filters/filter.h"
#include "ui_levels.h"
#include <atomic>

namespace QArv {

class LevelsFilter : public ImageFilter
{
public:
  LevelsFilter(ImageFilterPlugin* plugin);
  ImageFilterSettingsWidget* createSettingsWidget();
  void restoreSettings();
  void saveSettings();
  void filterImage(cv::Mat& image);

private:
  std::atomic<double> black, white, gamma;

  friend class LevelsSettingsWidget;
};

class LevelsPlugin : public QObject, public ImageFilterPlugin
{
  Q_OBJECT
  Q_INTERFACES(QArv::ImageFilterPlugin)
  // Q_PLUGIN_METADATA(IID "org.qt-project.Qt.LevelsPlugin" FILE
  // "LevelsPlugin.json") // Qt5
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QArvImageFilterPlugin" FILE
                        "LevelsPlugin.json") // Qt5

public:
  QString name();
  ImageFilter* makeFilter();
};

class LevelsSettingsWidget : public ImageFilterSettingsWidget,
                             private Ui_levelsSettingsWidget
{

  Q_OBJECT

public:
  LevelsSettingsWidget(ImageFilter* filter, QWidget* parent = 0,
                       Qt::WindowFlags f = 0);

protected slots:
  void setLiveUpdate(bool enabled);
  void applySettings();

private slots:
  void on_blackSlider_valueChanged(int value);
  void on_whiteSlider_valueChanged(int value);
  void on_gammaSlider_valueChanged(int value);
  void on_blackSpinbox_valueChanged(double value);
  void on_whiteSpinbox_valueChanged(double value);
  void on_gammaSpinbox_valueChanged(double value);

private:
  LevelsFilter* filter();
  int doubleToInt(double val);
  double intToDouble(int val);
};
};

#endif

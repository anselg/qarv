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
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "recorders/gstrecorders/mpeg4.h"
#include "recorders/gstrecorders/gstrecorder_implementation.h"

using namespace QArv;

Recorder*
Mpeg4Format::makeRecorder(QArvDecoder* decoder, QString fileName,
                               QSize frameSize, int framesPerSecond,
                               bool writeInfo)
{
  // x264enc could be an option instead of avenc_mpeg4. don't know enough about
  // encoders to say for sure. -A
  return makeGstRecorder({ "avenc_mpeg4", "mp4mux" },
                         "avenc_mpeg4 ! mp4mux", decoder, fileName, frameSize,
                         framesPerSecond, writeInfo);
}

Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QArvOutputFormat")

Q_IMPORT_PLUGIN(Mpeg4Format)

/*!
 * \bundle.cpp
 * \brief method definitions for working with bundles
 *
 * A bundle is a group of ar markers attached to an object. Bundles are defined in an xml file and
 * used by ar_track_avlar for robustness against occlusion. The bundle class defined here is used
 * for parsing these xml files to obtain information needed for projecting the bundle onto a map to
 * aid in obstacle avoidance.
 *
 * \author Steven Kordell, WPI - spkordell@wpi.edu
 * \date June 26, 2014
 */

#ifndef BUNDLE_H_
#define BUNDLE_H_

#include <ros/ros.h>
#include <tinyxml.h>

class Bundle
{
public:
  /*!
   * Creates a Bundle object
   */
  Bundle();

  /*!
   * Attempts to parse an xml bundle file at the given file location
   *\param filepath The location of the xml file
   *\returns True is parse is successful. False is parse fails.
   */
  bool parseBundle(char* filepath);

  /*
   * Returns the id of the ar marker associated with this bundle
   * \return The id of the ar marker associated with this bundle
   */
  int getId();

  /*
   * Returns the size of the ar markers
   * \returns The size of the ar markers
   */
  float getMarkerSize();

  /*
   * Returns the width of the bundle
   * \returns The width of the bundle
   */
  float getBundleWidth();

  /*
   * Returns the length of the bundle
   * \returns The length of the bundle
   */
  float getBundleHeight();

private:
  int id; /*!< associated bundle id */
  float markerSize; /*!< marker size */
  float bundleWidth; /*!< bundle width */
  float bundleHeight; /*!< bundle height */
};

#endif //BUNDLE_H
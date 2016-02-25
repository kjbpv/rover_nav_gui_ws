// Generated by gencpp from file rover_msgs/NavState.msg
// DO NOT EDIT!


#ifndef ROVER_MSGS_MESSAGE_NAVSTATE_H
#define ROVER_MSGS_MESSAGE_NAVSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rover_msgs
{
template <class ContainerAllocator>
struct NavState_
{
  typedef NavState_<ContainerAllocator> Type;

  NavState_()
    : position()
    , Vw(0.0)
    , phi(0.0)
    , theta(0.0)
    , psi(0.0)
    , chi(0.0)
    , p(0.0)
    , q(0.0)
    , r(0.0)
    , Vg(0.0)
    , base_latitude(0.0)
    , base_longitude(0.0)
    , base_altitude(0.0)  {
      position.assign(0.0);
  }
  NavState_(const ContainerAllocator& _alloc)
    : position()
    , Vw(0.0)
    , phi(0.0)
    , theta(0.0)
    , psi(0.0)
    , chi(0.0)
    , p(0.0)
    , q(0.0)
    , r(0.0)
    , Vg(0.0)
    , base_latitude(0.0)
    , base_longitude(0.0)
    , base_altitude(0.0)  {
      position.assign(0.0);
  }



   typedef boost::array<float, 3>  _position_type;
  _position_type position;

   typedef float _Vw_type;
  _Vw_type Vw;

   typedef float _phi_type;
  _phi_type phi;

   typedef float _theta_type;
  _theta_type theta;

   typedef float _psi_type;
  _psi_type psi;

   typedef float _chi_type;
  _chi_type chi;

   typedef float _p_type;
  _p_type p;

   typedef float _q_type;
  _q_type q;

   typedef float _r_type;
  _r_type r;

   typedef float _Vg_type;
  _Vg_type Vg;

   typedef double _base_latitude_type;
  _base_latitude_type base_latitude;

   typedef double _base_longitude_type;
  _base_longitude_type base_longitude;

   typedef double _base_altitude_type;
  _base_altitude_type base_altitude;




  typedef boost::shared_ptr< ::rover_msgs::NavState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rover_msgs::NavState_<ContainerAllocator> const> ConstPtr;

}; // struct NavState_

typedef ::rover_msgs::NavState_<std::allocator<void> > NavState;

typedef boost::shared_ptr< ::rover_msgs::NavState > NavStatePtr;
typedef boost::shared_ptr< ::rover_msgs::NavState const> NavStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rover_msgs::NavState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rover_msgs::NavState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace rover_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'rover_msgs': ['/home/kyle/gitMars/ros_nav_gui_ws/src/rover_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::rover_msgs::NavState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rover_msgs::NavState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rover_msgs::NavState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rover_msgs::NavState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rover_msgs::NavState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rover_msgs::NavState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rover_msgs::NavState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b2c76c6eb34da44397368c49a4c56269";
  }

  static const char* value(const ::rover_msgs::NavState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb2c76c6eb34da443ULL;
  static const uint64_t static_value2 = 0x97368c49a4c56269ULL;
};

template<class ContainerAllocator>
struct DataType< ::rover_msgs::NavState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rover_msgs/NavState";
  }

  static const char* value(const ::rover_msgs::NavState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rover_msgs::NavState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[3] position	# north, east, hieght (m)\n\
float32 Vw		# wheelspeed (m/s)\n\
float32 phi		# Roll angle (rad)\n\
float32 theta		# Pitch angle (rad)\n\
float32 psi		# Yaw angle (rad)\n\
float32 chi		# Course angle (rad)\n\
float32 p		# Body frame rollrate (rad/s)\n\
float32 q		# Body frame pitchrate (rad/s)\n\
float32 r		# Body frame yawrate (rad/s)\n\
float32 Vg		# Groundspeed (m/s)\n\
float64 base_latitude   # Latitude [degrees]. Positive is north of equator; negative is south.\n\
float64 base_longitude  # Longitude [degrees]. Positive is east of prime meridian; negative is west.\n\
float64 base_altitude   # Altitude [m]. Positive is above the WGS 84 ellipsoid\n\
";
  }

  static const char* value(const ::rover_msgs::NavState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rover_msgs::NavState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.Vw);
      stream.next(m.phi);
      stream.next(m.theta);
      stream.next(m.psi);
      stream.next(m.chi);
      stream.next(m.p);
      stream.next(m.q);
      stream.next(m.r);
      stream.next(m.Vg);
      stream.next(m.base_latitude);
      stream.next(m.base_longitude);
      stream.next(m.base_altitude);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct NavState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rover_msgs::NavState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rover_msgs::NavState_<ContainerAllocator>& v)
  {
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.position[i]);
    }
    s << indent << "Vw: ";
    Printer<float>::stream(s, indent + "  ", v.Vw);
    s << indent << "phi: ";
    Printer<float>::stream(s, indent + "  ", v.phi);
    s << indent << "theta: ";
    Printer<float>::stream(s, indent + "  ", v.theta);
    s << indent << "psi: ";
    Printer<float>::stream(s, indent + "  ", v.psi);
    s << indent << "chi: ";
    Printer<float>::stream(s, indent + "  ", v.chi);
    s << indent << "p: ";
    Printer<float>::stream(s, indent + "  ", v.p);
    s << indent << "q: ";
    Printer<float>::stream(s, indent + "  ", v.q);
    s << indent << "r: ";
    Printer<float>::stream(s, indent + "  ", v.r);
    s << indent << "Vg: ";
    Printer<float>::stream(s, indent + "  ", v.Vg);
    s << indent << "base_latitude: ";
    Printer<double>::stream(s, indent + "  ", v.base_latitude);
    s << indent << "base_longitude: ";
    Printer<double>::stream(s, indent + "  ", v.base_longitude);
    s << indent << "base_altitude: ";
    Printer<double>::stream(s, indent + "  ", v.base_altitude);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROVER_MSGS_MESSAGE_NAVSTATE_H
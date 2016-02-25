
(cl:in-package :asdf)

(defsystem "rover_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Pololu" :depends-on ("_package_Pololu"))
    (:file "_package_Pololu" :depends-on ("_package"))
    (:file "Drive" :depends-on ("_package_Drive"))
    (:file "_package_Drive" :depends-on ("_package"))
    (:file "NavState" :depends-on ("_package_NavState"))
    (:file "_package_NavState" :depends-on ("_package"))
    (:file "Arm" :depends-on ("_package_Arm"))
    (:file "_package_Arm" :depends-on ("_package"))
    (:file "SciFeedback" :depends-on ("_package_SciFeedback"))
    (:file "_package_SciFeedback" :depends-on ("_package"))
    (:file "NavGoal" :depends-on ("_package_NavGoal"))
    (:file "_package_NavGoal" :depends-on ("_package"))
  ))